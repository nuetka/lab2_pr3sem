#include "Header.h"

Track::Track() {
    name_ = "";
    genre_ = "";
    duration_ = 0;
    trackCount++;
}

Track::Track(const std::string& name) {
    name_ = name;
    genre_ = "";
    duration_ = 0;
    trackCount++;
}

Track::Track(const std::string& name, const std::string& genre, int duration) {
    name_ = name;
    genre_ = genre;
    duration_ = duration;
    trackCount++;
}

std::string Track::getName() const { return name_; }
std::string Track::getGenre() const { return genre_; }
int Track::getDuration() const { return duration_; }

void Track::setName(const std::string& name) { name_ = name; }
void Track::setGenre(const std::string& genre) { genre_ = genre; }
void Track::setDuration(int duration) { duration_ = duration; }
int Track::getTrackCount() { return trackCount; }
int Track::trackCount = 0;

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
    std::cout << "������� �������� �����: ";
    std::string name;
    std::getline(std::cin, name);
    setName(name);

    std::cout << "������� ����: ";
    std::string genre;
    std::getline(std::cin, genre);
    setGenre(genre);

    std::cout << "������� ����������������� � ���.: ";
    int duration;
    std::cin >> duration;
    setDuration(duration);
    std::cin.ignore();
}

void Track::printToConsole() const {
    std::cout << "�������� �����: " << getName() << std::endl;
    std::cout << "����: " << getGenre() << std::endl;
    std::cout << "����������������: " << getDuration() << "���." << std::endl;
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
    std::cout << "������� �������� �������: ";
    std::string name;
    std::getline(std::cin, name);
    setName(name);

    std::cout << "������� ��� ������� �������: ";
    int year;
    std::cin >> year;
    setYear(year);
    std::cin.ignore();

    std::cout << "������� ��� �����������: ";
    std::string artist;
    std::getline(std::cin, artist);
    setArtist(artist);

    std::cout << "������� ���������� ������ � �������: ";
    int trackCount;
    std::cin >> trackCount;
    std::cin.ignore();

    std::vector<Track> tracks;
    for (int i = 0; i < trackCount; ++i) {
        std::cout << "������� ���������� ��� ����� " << i + 1 << ":" << std::endl;
        std::cout << "  ��������: ";
        std::string trackName;
        std::getline(std::cin, trackName);

        std::cout << "  ����: ";
        std::string genre;
        std::getline(std::cin, genre);

        std::cout << "  ������������ (� ��������): ";
        int duration;
        std::cin >> duration;
        std::cin.ignore();

        Track track(trackName, genre, duration);
        tracks.push_back(track);
    }
    setTracks(tracks);
}

void Album::printToConsole() const {
    std::cout << "�������� �������: " << getName() << std::endl;
    std::cout << "��� �������: " << getYear() << std::endl;
    std::cout << "�����������: " << getArtist() << std::endl;
    std::cout << "�����: " << std::endl;

    int trackNumber = 1;
    for (const auto& track : getTracks()) {
        std::cout << "  ���� " << trackNumber << ":" << std::endl;
        std::cout << "    ��������: " << track.getName() << std::endl;
        std::cout << "    ����: " << track.getGenre() << std::endl;
        std::cout << "    ������������: " << track.getDuration() << " ���." << std::endl;
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
        std::cout << "���� \"" << track.getName() << "\" ��� ���������� � ���� �������." << std::endl;
    }
}

void Album::removeTrack(const std::string& trackName) {
    for (auto it = tracks_.begin(); it != tracks_.end(); ++it) {
        if (it->getName() == trackName) {
            tracks_.erase(it); // �������� ���������� ����� �� ������
            break; // ����� �� ����� ������ �����
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
    std::cout << "������� �������� ���������: ";
    std::string name;
    std::getline(std::cin, name);
    setName(name);

    std::cout << "������� ���������� ������ � ���������: ";
    int trackCount;
    std::cin >> trackCount;
    std::cin.ignore();

    std::vector<Track> tracks;
    for (int i = 0; i < trackCount; ++i) {
        std::cout << "������� ���������� ��� ����� " << i + 1 << ":" << std::endl;
        std::cout << "  ��������: ";
        std::string trackName;
        std::getline(std::cin, trackName);

        std::cout << "  ����: ";
        std::string genre;
        std::getline(std::cin, genre);

        std::cout << "  ������������ (� ��������): ";
        int duration;
        std::cin >> duration;
        std::cin.ignore();

        Track track(trackName, genre, duration);
        tracks.push_back(track);
    }
    setTracks(tracks);
}

void Playlist::printToConsole() const {
    std::cout << "�������� ���������: " << getName() << std::endl;
    std::cout << "�����: " << std::endl;

    int trackNumber = 1;
    for (const auto& track : getTracks()) {
        std::cout << "  ���� " << trackNumber << ":" << std::endl;
        std::cout << "    ��������: " << track.getName() << std::endl;
        std::cout << "    ����: " << track.getGenre() << std::endl;
        std::cout << "    ������������: " << track.getDuration() << " ���." << std::endl;
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
    std::cout << "������� ��� �����������: ";
    std::string name;
    std::getline(std::cin, name);
    setName(name);

    std::cout << "������� ���������� ��������: ";
    int albumCount;
    std::cin >> albumCount;
    std::cin.ignore();

    std::vector<Album> albums;
    for (int i = 0; i < albumCount; ++i) {
        std::cout << "������� ���������� ��� ������� " << i + 1 << ":" << std::endl;
        Album album;
        album.readFromConsole();
        albums.push_back(album);
    }
    setAlbums(albums);
}

void Artist::printToConsole() const {
    std::cout << "��� �����������: " << getName() << std::endl;
    std::cout << "�������: " << std::endl;

    int albumNumber = 1;
    for (const auto& album : getAlbums()) {
        std::cout << "  ������ " << albumNumber << ":" << std::endl;
        std::cout << "    ��������: " << album.getName() << std::endl;
        std::cout << "    ��� �������: " << album.getYear() << std::endl;
        std::cout << "    �����: " << std::endl;

        int trackNumber = 1;
        for (const auto& track : album.getTracks()) {
            std::cout << "      ���� " << trackNumber << ":" << std::endl;
            std::cout << "        ��������: " << track.getName() << std::endl;
            std::cout << "        ����: " << track.getGenre() << std::endl;
            std::cout << "        ������������: " << track.getDuration() << " ���." << std::endl;
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
    // ��������� ������������� ������� ����� �����������
    for (const auto& existingAlbum : albums_) {
        if (existingAlbum.getName() == album.getName()) {
            std::cout << "������ \"" << album.getName() << "\" ��� ���������� � ���� ����������." << std::endl;
            return;
        }
    }
    // ��������� ������, ���� �� �� ����������
    albums_.push_back(album);
}

void Library::readFromConsole() {
    std::cout << "������� ���������� ��������: ";
    int albumCount;
    std::cin >> albumCount;
    std::cin.ignore();

    for (int i = 0; i < albumCount; ++i) {
        std::cout << "������� ���������� ��� ������� " << i + 1 << ":" << std::endl;
        Album album;
        album.readFromConsole();
        addAlbum(album);
    }

    std::cout << "������� ���������� ����������: ";
    int playlistCount;
    std::cin >> playlistCount;
    std::cin.ignore();

    for (int i = 0; i < playlistCount; ++i) {
        std::cout << "������� ���������� ��� ��������� " << i + 1 << ":" << std::endl;
        Playlist playlist;
        playlist.readFromConsole();
        playlists_.push_back(playlist);
    }
}

void Library::printToConsole() {
    std::cout << "�������:" << std::endl;
    int albumNumber = 1;
    for (const auto& album : getAlbums()) {
        std::cout << "������ " << albumNumber << ":" << std::endl;
        album.printToConsole();
        std::cout << std::endl;
        ++albumNumber;
    }

    std::cout << "���������:" << std::endl;
    int playlistNumber = 1;
    for (const auto& playlist : getPlaylists()) {
        std::cout << "�������� " << playlistNumber << ":" << std::endl;
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
