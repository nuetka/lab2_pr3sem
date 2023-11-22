#pragma once
#include <iostream>
#include <string>
#include <vector>

class Track {
public:
    Track();
    Track(const std::string& name);
    Track(const std::string& name, const std::string& genre, int duration);

    std::string getName() const;
    std::string getGenre() const;
    int getDuration() const;

    void setName(const std::string& name);
    void setGenre(const std::string& genre);
    void setDuration(int duration);

    static std::vector<Track> findTracksByGenre(const std::vector<Track>& tracks, const std::string& genre);

    void readFromConsole();
    void printToConsole() const;
    static int getTrackCount();

private:
    std::string name_;
    std::string genre_;
    int duration_;

    static int trackCount;
};

class Album {
public:
    Album();
    Album(const std::string& name, int year, const std::string& artist, const std::vector<Track>& tracks);
    Album(const std::string& name);

    std::string getName() const;
    int getYear() const;
    std::string getArtist() const;
    std::vector<Track> getTracks() const;

    void setName(const std::string& name);
    void setYear(int year);
    void setArtist(const std::string& artist);
    void setTracks(const std::vector<Track>& tracks);

    void readFromConsole();
    void printToConsole() const;

    void addTrack(const Track& track);
    void removeTrack(const std::string& trackName);

    static std::vector<Album> findAlbumsByYear(const std::vector<Album>& albums, int year);

private:
    std::string name_;
    int year_;
    std::string artist_;
    std::vector<Track> tracks_;
};

class Playlist {
public:
    Playlist();
    Playlist(const std::string& name, const std::vector<Track>& tracks);
    Playlist(const std::string& name);

    std::string getName() const;
    std::vector<Track> getTracks() const;

    void setName(const std::string& name);
    void setTracks(const std::vector<Track>& tracks);

    void readFromConsole();
    void printToConsole() const;

private:
    std::string name_;
    std::vector<Track> tracks_;
};

class Artist {
public:
    Artist();
    Artist(const std::string& name, const std::vector<Album>& albums);
    Artist(const std::string& name);

    std::string getName() const;
    std::vector<Album> getAlbums() const;

    void setName(const std::string& name);
    void setAlbums(const std::vector<Album>& albums);

    void readFromConsole();
    void printToConsole() const;

private:
    std::string name_;
    std::vector<Album> albums_;
};

class Library {
public:
    Library();
    Library(const std::vector<Album>& albums, const std::vector<Playlist>& playlists);
    Library(const std::vector<Album>& albums);

    std::vector<Album> getAlbums() const;
    std::vector<Playlist> getPlaylists() const;

    void setAlbums(const std::vector<Album>& albums);
    void setPlaylists(const std::vector<Playlist>& playlists);

    void addAlbum(const Album& album);

    void readFromConsole();
    void printToConsole();

private:
    std::vector<Album> albums_;
    std::vector<Playlist> playlists_;
};
