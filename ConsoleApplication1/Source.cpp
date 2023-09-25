#include "Header.h"

Track::Track() {
    name_ = "";
    genre_ = "";
    duration_ = 0;
}

Track::Track(const std::string& name) {
    name_ = name;
    genre_ = "";
    duration_ = 0;
}

Track::Track(const std::string& name, const std::string& genre, int duration) {
    name_ = name;
    genre_ = genre;
    duration_ = duration;
}

std::string Track::getName() const { return name_; }
std::string Track::getGenre() const { return genre_; }
int Track::getDuration() const { return duration_; }

void Track::setName(const std::string& name) { name_ = name; }
void Track::setGenre(const std::string& genre) { genre_ = genre; }
void Track::setDuration(int duration) { duration_ = duration; }

std::vector<Track> Track::findTracksByGenre(const std::vector<Track>& tracks, const std::string& genre) {
    std::vector<Track> result;
    for (const auto& track : tracks) {
        if (track.getGenre() == genre) {
            result.push_back(track);
        }
    }
    return result;
}

void Track::readFromConsole() {
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

void Track::printToConsole() const {
    std::cout << "Название трека: " << getName() << std::endl;
    std::cout << "Жанр: " << getGenre() << std::endl;
    std::cout << "Подолжительность: " << getDuration() << "сек." << std::endl;
}


Album::Album() {
    name_ = "";
    year_ = 0;
    artist_ = "";
    tracks_ = std::vector<Track>();
}

Album::Album(const std::string& name, int year, const std::string& artist, const std::vector<Track>& tracks) {
    name_ = name;
    year_ = year;
    artist_ = artist;
    tracks_ = tracks;
}

Album::Album(const std::string& name) {
    name_ = name;
    year_ = 0;
    artist_ = "";
    tracks_ = std::vector<Track>();
}

std::string Album::getName() const { return name_; }
int Album::getYear() const { return year_; }
std::string Album::getArtist() const { return artist_; }
std::vector<Track> Album::getTracks() const { return tracks_; }

void Album::setName(const std::string& name) { name_ = name; }
void Album::setYear(int year) { year_ = year; }
void Album::setArtist(const std::string& artist) { artist_ = artist; }
void Album::setTracks(const std::vector<Track>& tracks) { tracks_ = tracks; }

void Album::readFromConsole() {
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

void Album::printToConsole() const {
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

void Album::addTrack(const Track& track) {
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

void Album::removeTrack(const std::string& trackName) {
    for (auto it = tracks_.begin(); it != tracks_.end(); ++it) {
        if (it->getName() == trackName) {
            tracks_.erase(it); // удаление найденного трека из списка
            break; // выход из цикла поиска трека
        }
    }
}


Playlist::Playlist() {
    name_ = "";
    tracks_ = std::vector<Track>();
}

Playlist::Playlist(const std::string& name, const std::vector<Track>& tracks) {
    name_ = name;
    tracks_ = tracks;
}

Playlist::Playlist(const std::string& name) {
    name_ = name;
    tracks_ = std::vector<Track>();
}

std::string Playlist::getName() const { return name_; }
std::vector<Track> Playlist::getTracks() const { return tracks_; }

void Playlist::setName(const std::string& name) { name_ = name; }
void Playlist::setTracks(const std::vector<Track>& tracks) { tracks_ = tracks; }

void Playlist::readFromConsole() {
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

void Playlist::printToConsole() const {
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


Artist::Artist() {
    name_ = "";
    albums_ = std::vector<Album>();
}

Artist::Artist(const std::string& name, const std::vector<Album>& albums) {
    name_ = name;
    albums_ = albums;
}

Artist::Artist(const std::string& name) {
    name_ = name;
    albums_ = std::vector<Album>();
}

std::string Artist::getName() const { return name_; }
std::vector<Album> Artist::getAlbums() const { return albums_; }

void Artist::setName(const std::string& name) { name_ = name; }
void Artist::setAlbums(const std::vector<Album>& albums) { albums_ = albums; }

void Artist::readFromConsole() {
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

void Artist::printToConsole() const {
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

Library::Library() {
    albums_ = std::vector<Album>();
    playlists_ = std::vector<Playlist>();
}

Library::Library(const std::vector<Album>& albums, const std::vector<Playlist>& playlists) {
    albums_ = albums;
    playlists_ = playlists;
}

Library::Library(const std::vector<Album>& albums) {
    albums_ = albums;
    playlists_ = std::vector<Playlist>();
}

std::vector<Album> Library::getAlbums() const { return albums_; }
std::vector<Playlist> Library::getPlaylists() const { return playlists_; }

void Library::setAlbums(const std::vector<Album>& albums) { albums_ = albums; }
void Library::setPlaylists(const std::vector<Playlist>& playlists) { playlists_ = playlists; }

void Library::addAlbum(const Album& album) {
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

void Library::readFromConsole() {
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

void Library::printToConsole() {
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

std::vector<Album> Album::findAlbumsByYear(const std::vector<Album>& albums, int year) {
    std::vector<Album> result;
    for (const auto& album : albums) {
        if (album.getYear() == year) {
            result.push_back(album);
        }
    }
    return result;
}
