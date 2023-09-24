#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include "Header.h"

class Track {
public:
    Track() {
        name_ = "";
        genre_ = "";
        duration_ = 0;
    
    }
    Track(const std::string& name) {
        name_=name;
        genre_ = "";
        duration_ = 0;
    }
    Track(const std::string& name, const std::string& genre, int duration) {

        name_=name;
        genre_=genre;
        duration_=duration;

    }
    std::string getName() const { return name_; }
    std::string getGenre() const { return genre_; }
    int getDuration() const { return duration_; }

    void setName(const std::string& name) { name_ = name; }
    void setGenre(const std::string& genre) { genre_ = genre; }
    void setDuration(int duration) { duration_ = duration; }

    static std::vector<Track> findTracksByGenre(const std::vector<Track>& tracks, const std::string& genre) {
        std::vector<Track> result;
        for (const auto& track : tracks) {
            if (track.getGenre() == genre) {
                result.push_back(track);
            }
        }
        return result;
    }

    void readFromConsole() {
        std::cout << "Введите название трека: ";
        std::string name;
        std::getline(std::cin, name);
        setName(name);

        std::cout << "Введите жанр: ";
        std::string genre;
        std::getline(std::cin, genre);
        setGenre(genre);

        std::cout << "Введите продолжительность в сек.: ";
        int duration;
        std::cin >> duration;
        setDuration(duration);
        std::cin.ignore();

        
    }

    void printToConsole() const{
        std::cout << "Название трека: " << getName() << std::endl;
        std::cout << "Жанр: " << getGenre() << std::endl;
        std::cout << "Подолжительность: " << getDuration() <<"сек."<< std::endl;
        
    }
private:
    std::string name_;
    std::string genre_;
    int duration_;
};


class Album {
public:
    Album() {
        name_ = "";
        year_ = 0;
        artist_ = "";
    }
    Album(const std::string& name, int year, const std::string& artist, const std::vector<Track>& tracks) {
        name_ = name;
        year_ = year;
        artist_ = artist;
        tracks_ = tracks;
    }
    Album(const std::string& name) {
        name_ = name;
        year_ = 0;
        artist_ = "";
    }
    std::string getName() const { return name_; }
    int getYear() const { return year_; }
    std::string getArtist() const { return artist_; }
    std::vector<Track> getTracks() const { return tracks_; }
    void setName(const std::string& name) { name_ = name; }
    void setYear(int year) { year_ = year; }
    void setArtist(const std::string& artist) { artist_ = artist; }
    void setTracks(const std::vector<Track>& tracks) { tracks_ = tracks; }

    void readFromConsole() {
        std::cout << "Введите название альбома: ";
        std::string name;
        std::getline(std::cin, name);
        setName(name);

        std::cout << "Введите год выпуска альбома: ";
        int year;
        std::cin >> year;
        setYear(year);
        std::cin.ignore();

        std::cout << "Введите имя исполнителя: ";
        std::string artist;
        std::getline(std::cin, artist);
        setArtist(artist);

        std::cout << "Введите количество треков в альбоме: ";
        int trackCount;
        std::cin >> trackCount;
        std::cin.ignore();

        std::vector<Track> tracks;
        for (int i = 0; i < trackCount; ++i) {
            std::cout << "Введите информацию для трека " << i + 1 << ":" << std::endl;
            std::cout << "  Название: ";
            std::string trackName;
            std::getline(std::cin, trackName);

            std::cout << "  Жанр: ";
            std::string genre;
            std::getline(std::cin, genre);

            std::cout << "  Длительность (в секундах): ";
            int duration;
            std::cin >> duration;
            std::cin.ignore();

            Track track(trackName, genre, duration);
            tracks.push_back(track);
        }
        setTracks(tracks);
    }

    void printToConsole() const{
        std::cout << "Название альбома: " << getName() << std::endl;
        std::cout << "Год выпуска: " << getYear() << std::endl;
        std::cout << "Исполнитель: " << getArtist() << std::endl;
        std::cout << "Треки: " << std::endl;

        int trackNumber = 1;
        for (const auto& track : getTracks()) {
            std::cout << "  Трек " << trackNumber << ":" << std::endl;
            std::cout << "    Название: " << track.getName() << std::endl;
            std::cout << "    Жанр: " << track.getGenre() << std::endl;
            std::cout << "    Длительность: " << track.getDuration() << " сек." << std::endl;
            ++trackNumber;
        }
    }

    void addTrack(const Track& track) {
        bool trackExists = false;
        for (const auto& existingTrack : tracks_) {
            if (existingTrack.getName() == track.getName()) {
                trackExists = true;
                break;
            }
        }

        if (!trackExists) {
            tracks_.push_back(track);
        }
        else {
            std::cout << "Трек \"" << track.getName() << "\" уже существует в этом альбоме." << std::endl;
        }
    }

    void removeTrack(const std::string& trackName) {
        for (auto it = tracks_.begin(); it != tracks_.end(); ++it) {
            if (it->getName() == trackName) {
                tracks_.erase(it); // удаление найденного трека из списка
                break; // выход из цикла поиска трека
            }
        }
    }

    static std::vector<Album> findAlbumsByYear(const std::vector<Album>& albums, int year) {
        std::vector<Album> result;
        for (const auto& album : albums) {
            if (album.getYear() == year) {
                result.push_back(album);
            }
        }
        return result;
    }
private:
    std::string name_;
    int year_;
    std::string artist_;
    std::vector<Track> tracks_;
};

class Playlist {
public:
    Playlist() {
        name_ = "";
        
    }
    Playlist(const std::string& name, const std::vector<Track>& tracks) {
        name_ = name;
        tracks_ = tracks;
    }
    Playlist(const std::string& name) {
        name_ = name;
    }
    std::string getName() const { return name_; }
    std::vector<Track> getTracks() const { return tracks_; }
    void setName(const std::string& name) { name_ = name; }
    void setTracks(const std::vector<Track>& tracks) { tracks_ = tracks; }

    void readFromConsole() {
        std::cout << "Введите название плейлиста: ";
        std::string name;
        std::getline(std::cin, name);
        setName(name);

        std::cout << "Введите количество треков в плейлисте: ";
        int trackCount;
        std::cin >> trackCount;
        std::cin.ignore();

        std::vector<Track> tracks;
        for (int i = 0; i < trackCount; ++i) {
            std::cout << "Введите информацию для трека " << i + 1 << ":" << std::endl;
            std::cout << "  Название: ";
            std::string trackName;
            std::getline(std::cin, trackName);

            std::cout << "  Жанр: ";
            std::string genre;
            std::getline(std::cin, genre);

            std::cout << "  Длительность (в секундах): ";
            int duration;
            std::cin >> duration;
            std::cin.ignore();

            Track track(trackName, genre, duration);
            tracks.push_back(track);
        }
        setTracks(tracks);
    }

    void printToConsole() const {
        std::cout << "Название плейлиста: " << getName() << std::endl;
        std::cout << "Треки: " << std::endl;

        int trackNumber = 1;
        for (const auto& track : getTracks()) {
            std::cout << "  Трек " << trackNumber << ":" << std::endl;
            std::cout << "    Название: " << track.getName() << std::endl;
            std::cout << "    Жанр: " << track.getGenre() << std::endl;
            std::cout << "    Длительность: " << track.getDuration() << " сек." << std::endl;
            ++trackNumber;
        }
    }

private:
    std::string name_;
    std::vector<Track> tracks_;
};

class Artist {
public:
    Artist() {
        name_ = "";
    }
    Artist(const std::string& name, const std::vector<Album>& albums) {
        name_ = name;
        albums_ = albums;
    }
    Artist(const std::string& name) {
        name_ = name;
    }
    std::string getName() const { return name_; }
    std::vector<Album> getAlbums() const { return albums_; }
    void setName(const std::string& name) { name_ = name; }
    void setAlbums(const std::vector<Album>& albums) { albums_ = albums; }

    void readFromConsole() {
        std::cout << "Введите имя исполнителя: ";
        std::string name;
        std::getline(std::cin, name);
        setName(name);

        std::cout << "Введите количество альбомов: ";
        int albumCount;
        std::cin >> albumCount;
        std::cin.ignore();

        std::vector<Album> albums;
        for (int i = 0; i < albumCount; ++i) {
            std::cout << "Введите информацию для альбома " << i + 1 << ":" << std::endl;
            Album album;
            album.readFromConsole();
            albums.push_back(album);
        }
        setAlbums(albums);
    }

    void printToConsole() const {
        std::cout << "Имя исполнителя: " << getName() << std::endl;
        std::cout << "Альбомы: " << std::endl;

        int albumNumber = 1;
        for (const auto& album : getAlbums()) {
            std::cout << "  Альбом " << albumNumber << ":" << std::endl;
            std::cout << "    Название: " << album.getName() << std::endl;
            std::cout << "    Год выпуска: " << album.getYear() << std::endl;
            std::cout << "    Треки: " << std::endl;

            int trackNumber = 1;
            for (const auto& track : album.getTracks()) {
                std::cout << "      Трек " << trackNumber << ":" << std::endl;
                std::cout << "        Название: " << track.getName() << std::endl;
                std::cout << "        Жанр: " << track.getGenre() << std::endl;
                std::cout << "        Длительность: " << track.getDuration() << " сек." << std::endl;
                ++trackNumber;
            }
            ++albumNumber;
        }
    }

private:
    std::string name_;
    std::vector<Album> albums_;
};


class Library {
public:
    Library() {}

    Library(const std::vector<Album>& albums, const std::vector<Playlist>& playlists) {
        albums_ = albums;
        playlists_ = playlists;
    }

    Library(const std::vector<Album>& albums) {

        albums_ = albums;

    }
    std::vector<Album> getAlbums() const { return albums_; }
    std::vector<Playlist> getPlaylists() const { return playlists_; }

    void setAlbums(const std::vector<Album>& albums) { albums_ = albums; }
    void setPlaylists(const std::vector<Playlist>& playlists) { playlists_ = playlists; }

    void addAlbum(const Album& album) {
        // Проверяет существование альбома перед добавлением
        for (const auto& existingAlbum : albums_) {
            if (existingAlbum.getName() == album.getName()) {
                std::cout << "Альбом \"" << album.getName() << "\" уже существует в этой библиотеке." << std::endl;
                return;
            }
        }
        // Добавляет альбом, если он не существует
        albums_.push_back(album);
    }

    void readFromConsole() {
        std::cout << "Введите количество альбомов: ";
        int albumCount;
        std::cin >> albumCount;
        std::cin.ignore();

        for (int i = 0; i < albumCount; ++i) {
            std::cout << "Введите информацию для альбома " << i + 1 << ":" << std::endl;
            Album album;
            album.readFromConsole();
            addAlbum(album);
        }

        std::cout << "Введите количество плейлистов: ";
        int playlistCount;
        std::cin >> playlistCount;
        std::cin.ignore();

        for (int i = 0; i < playlistCount; ++i) {
            std::cout << "Введите информацию для плейлиста " << i + 1 << ":" << std::endl;
            Playlist playlist;
            playlist.readFromConsole();
            playlists_.push_back(playlist);
        }
    }


    void printToConsole() {
        std::cout << "Альбомы:" << std::endl;
        int albumNumber = 1;
        for (const auto& album : getAlbums()) {
            std::cout << "Альбом " << albumNumber << ":" << std::endl;
            album.printToConsole();
            std::cout << std::endl;
            ++albumNumber;
        }

        std::cout << "Плейлисты:" << std::endl;
        int playlistNumber = 1;
        for (const auto& playlist : getPlaylists()) {
            std::cout << "Плейлист " << playlistNumber << ":" << std::endl;
            playlist.printToConsole();
            std::cout << std::endl;
            ++playlistNumber;
        }
    }
private:
    std::vector<Album> albums_;
    std::vector<Playlist> playlists_;
};

int main() {

    setlocale(LC_ALL, "Rus");
    Track track1("Track 1", "Genre 1", 180);
    Track track2("Track 2", "Genre 2", 240);
    Track track3("Track 3", "Genre 3", 300);
    Track track4;
    track4.readFromConsole();
    Track track5("Track 5");


    std::vector<Track> tracks;
    tracks.push_back(track1);
    tracks.push_back(track2);
    tracks.push_back(track3);
    tracks.push_back(track4);
    tracks.push_back(track5);

    std::cout << std::endl;
    std::cout << "Все треки с жанром Genre 2:" << std::endl;
    std::vector<Track> tracksByGenre = Track::findTracksByGenre(tracks, "Genre 2");
    for (const auto& track : tracksByGenre) {
        track.printToConsole();
    }

    Album album("Album 0", 2022, "Artist 0", tracks);
    Album album0;
    std::cout << std::endl;
    album0.readFromConsole();
    std::cout << std::endl;
    album0.printToConsole();

    std::cout << std::endl;
    std::vector<Album> albums;
    albums.push_back(album);
    albums.push_back(album0);
    

    std::cout <<"Добавление Track1 и удаление Track 2" << std::endl;
    std::cout << "До" << std::endl;
    album0.printToConsole();
    album0.addTrack(track1);
    album0.removeTrack("Track 2");
    std::cout << std::endl;
    std::cout << "После" << std::endl;
    album0.printToConsole();
    std::cout << std::endl;

    Album album1("Album1", 1995, "Artist1", {});
    Album album2("Album2", 2000, "Artist2", {});
    Album album3("Album3", 1995, "Artist3", {});

    std::vector<Album> allAlbums = { album1, album2, album3 };

    std::vector<Album> albumsByYear = Album::findAlbumsByYear(allAlbums, 1995);

    for (const auto& album : albumsByYear) {
        std::cout << "Найдены альбом(-ы) 1995 года: " << album.getName() << " by " << album.getArtist() << std::endl;
    }
    std::cout << std::endl;

    Playlist playlist1("Playlist1", tracks);
    Playlist playlist2;
    playlist2.readFromConsole();
    std::cout << std::endl;

    std::vector<Playlist> allPlaylists = { playlist1, playlist2 };

    Library library(albums, allPlaylists);
    std::cout <<"Добавление альбома в библиотеку" << std::endl;
    std::cout << "До" << std::endl;
    library.printToConsole();
    std::cout << std::endl;
    library.addAlbum(album2);
    std::cout << "После" << std::endl;
    library.printToConsole();
    std::cout << std::endl;

    return 0;
}