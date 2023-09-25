#include "Header.h"

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
        std::cout << "Найдены альбом(-ы) 1995 года: " << album.getName() << " - " << album.getArtist() << std::endl;
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