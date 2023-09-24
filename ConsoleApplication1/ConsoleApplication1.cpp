#include "Header.h"


int main() {
    setlocale(LC_ALL, "Rus");
    printf("Инициализация и заполнение треков\n");
    //iniz_track();
    input_track();

    printf("\n");
    //iniz_track();
    input_track();

    printf("\n");
    //iniz_track();
    input_track();

    printf("\n");
    output_track();

    printf("\n");
    char genre[10] = "k-pop";
    search_tracks_by_genre(genre);
    printf("\n");

    printf("Инициализация и заполнение альбома\n");
    //iniz_album();
    input_album();
    printf("\n");
    output_album();

    printf("\nУдаляем один из треков из альбома:\n");
    char track_name[N]="LOL", album_name[N]="XEX";
    del_track_from_album(track_name, album_name);
    output_album();

    printf("\n");
    printf("Инициализация и заполнение плейлиста\n");
    //iniz_playlist();
    input_playlist();
    printf("\n");
    output_playlist();
    printf("\n");
    printf("Инициализация и заполнение исполнителя\n");
   // iniz_artist();
    input_artist();
    printf("\n");
    output_artist();
    printf("\n");
    printf("Инициализация и заполнение библиотеки\n");
    //iniz_library();
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

    clean_tracks();
    clean_albums();
    clean_playlists();
    clean_artists();
    clean_libs();

    return 0;
}