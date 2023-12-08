#pragma once
#include <iostream>
#include <string>
#include <vector>

class MediaItem {
public:
    virtual std::string getMediaType() const = 0;
};

class Movie : public MediaItem {
private:
    std::string title;
    int duration;  

public:
    Movie(const std::string& title) {
        this->title = title;
    }
    
    std::string getMediaType() const override { return "Movie "; }

   
};

class Track : public MediaItem {
public:
    Track();
    Track(const std::string& name);
    Track(const std::string& name, const std::string& genre, int duration);
    std::string getName() const;
    std::string getGenre() const;
    int getDuration() const;

    std::string getMediaType() const override { return "Track"; }

    void setName(const std::string& name);
    void setGenre(const std::string& genre);
    void setDuration(int duration);

    static std::vector<Track> findTracksByGenre(const std::vector<Track>& tracks, const std::string& genre);
    static std::vector<Track>* findTracksByGenrePointer(const std::vector<Track>& tracks, const std::string& genre);
    static void findTracksByGenreReference(const std::vector<Track>& tracks, const std::string& genre, std::vector<Track>& result);

    void readFromConsole();
    void printToConsole() const;
    static int getTrackCount();
    friend Track operator+(const Track& track1, const Track& track2);
    friend Track operator++(Track& track, int); // Префиксный вариант
    friend Track operator++(Track& track); // Постфиксный вариант
    virtual void printDetails() const;
    friend std::ostream& operator<<(std::ostream& os, const Track& track);
    static void printTrack(const Track& track);
    void printDetailsNV() const;
protected:
    std::string name_;
    std::string genre_;
    int duration_;
private:
    static int trackCount;
};


//добавлено поле для хранения информации о рейтинге трека.
class ExtendedTrack : public Track {
public:
    ExtendedTrack& operator=(const Track& other);

    ExtendedTrack();
    ExtendedTrack(const std::string& name, const std::string& genre, int duration, int rating);

    int getRating() const;
    void setRating(int rating);

    void readFromConsole();
    void printToConsole(bool printOnlyRating) const;

    void printProtectedFields();

    friend std::ostream& operator<<(std::ostream& os, const ExtendedTrack& extendedTrack);
    void printDetails() const override;
    void printDetailsNV() const;

private:
    int rating_;
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
    // Получение экземпляра синглтона
    static Library& getInstance() {
        static Library instance;
        return instance;
    }

    std::vector<Album> getAlbums() const;
    std::vector<Playlist> getPlaylists() const;

    void setAlbums(const std::vector<Album>& albums);
    void setPlaylists(const std::vector<Playlist>& playlists);

    void addAlbum(const Album& album);

    void readFromConsole();
    void printToConsole();

private:
    // Приватный конструктор для предотвращения создания объектов извне
    Library() {}

    // Запрещаем копирование и присваивание
    Library(const Library&) = delete;
    Library& operator=(const Library&) = delete;

    std::vector<Album> albums_;
    std::vector<Playlist> playlists_;
};

