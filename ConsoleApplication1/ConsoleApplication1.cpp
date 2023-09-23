#include "Header.h"


int main() {
    setlocale(LC_ALL, "Rus");
    printf("Инициализация и заполнение треков\n");
    iniz_track();
    input_track();

    printf("\n");
    iniz_track();
    input_track();

    printf("\n");
    iniz_track();
    input_track();

    printf("\n");
    output_track();

    printf("\n");
    char genre[10] = "k-pop";
    search_tracks_by_genre(genre);
    printf("\n");

    printf("Инициализация и заполнение альбома\n");
    iniz_album();
    input_album();
    printf("\n");
    output_album();
    printf("\n");
    printf("Инициализация и заполнение плейлиста\n");
    iniz_playlist();
    input_playlist();
    printf("\n");
    output_playlist();
    printf("\n");
    printf("Инициализация и заполнение исполнителя\n");
    iniz_artist();
    input_artist();
    printf("\n");
    output_artist();
    printf("\n");
    printf("Инициализация и заполнение библиотеки\n");
    input_library();
    printf("\n");
    output_library();
    printf("\n");
    add_track_to_album();
    printf("\n");
    output_album();
    printf("\n");
    add_album_to_library();
    printf("\n");
    output_library();
    printf("\n");
    search_albums_by_year(2018);

  
    free(tracks);
    for (int i = 0; i < num_albums; i++) {
        free(albums[i].a_tracks);
    }
    free(albums);

    for (int i = 0; i < num_playlists; i++) {
        free(playlists[i].tracks);
    }
    free(playlists);

    for (int i = 0; i < num_artists; i++) {
        free(artists[i].albums);
    }
    free(artists);

    for (int i = 0; i < num_libs; i++) {
        free(libs[i].albums);
        free(libs[i].playlists);
    }
    free(libs);

    return 0;
}