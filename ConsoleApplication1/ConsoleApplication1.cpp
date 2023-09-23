#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define N 50

typedef struct track {
    char name[N];
    int duration;
    char genre[N];
} Track;

typedef struct album {
    char name[N];
    int year;
    char artist[N];
    Track* a_tracks;
    int track_count;
} Album;

typedef struct playlist {
    char name[N];
    Track* tracks;
    int track_count;
} Playlist;

typedef struct artist {
    char name[N];
    Album* albums;
    int album_count;
} Artist;

typedef struct library {
    Album* albums;
    int album_count;
    Playlist* playlists;
    int playlist_count;
} Library;


int num_tracks = 0;
Track* tracks = (Track*)malloc(0 * sizeof(Track));

int num_albums = 0;
Album* albums = (Album*)malloc(0 * sizeof(Album));

int num_playlists = 0;
Playlist* playlists = (Playlist*)malloc(0 * sizeof(Playlist));

int num_artists = 0;
Artist* artists = (Artist*)malloc(0 * sizeof(Artist));

int num_libs = 0;
Library* libs = (Library*)malloc(0 * sizeof(Library));

void iniz_track() {
    static int MAX_TRACKS = 0;

    MAX_TRACKS += 1;
    Track* new_tracks = (Track*)realloc(tracks, MAX_TRACKS * sizeof(Track));
    if (new_tracks == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    tracks = new_tracks;
}

void input_track() {
    Track new_track;
    printf("Введите название трека: ");
    scanf("%s", new_track.name);
    while (getchar() != '\n');
    printf("Введите продолжительность трека (в секундах): ");
    scanf("%d", &new_track.duration);
    while (getchar() != '\n');
    printf("Введите жанр трека: ");
    scanf("%s", new_track.genre);
    while (getchar() != '\n');

    tracks[num_tracks] = new_track;
    num_tracks += 1;
}

void output_track() {
    printf("Созданные треки:\n");
    for (int i = 0; i < num_tracks; i++) {
        printf("%d. %s - %d сек. (%s)\n", i + 1, tracks[i].name, tracks[i].duration, tracks[i].genre);
    }
}

void iniz_album() {
    static int MAX_ALBUMS = 0;
    MAX_ALBUMS += 1;

    Album* new_albums = (Album*)realloc(albums, MAX_ALBUMS * sizeof(Album));
    if (new_albums == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    albums = new_albums;
}

void input_album() {
    Album new_album;
    int count, num;
    printf("Введите название альбома: ");
    scanf("%s", new_album.name);
    while (getchar() != '\n');
    printf("Введите год выпуска: ");
    scanf("%d", &new_album.year);
    while (getchar() != '\n');
    printf("Введите исполнителя: ");
    scanf("%s", new_album.artist);
    while (getchar() != '\n');
    printf("Введите количество треков:\n");

    scanf("%d", &count);
    while (getchar() != '\n');
    printf("Введите номера треков:\n");
    output_track();

    new_album.a_tracks = (Track*)malloc(count * sizeof(Track));
    if (new_album.a_tracks == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        scanf("%d", &num);
        while (getchar() != '\n');
        memcpy(&new_album.a_tracks[i], &tracks[num - 1], sizeof(Track));
    }
    new_album.track_count = count;

    albums[num_albums] = new_album;
    num_albums += 1;
}

void output_album() {
    printf("Список альбомов:\n");
    for (int i = 0; i < num_albums; i++) {
        printf("%d. %s(%d) - %s\n", i + 1, albums[i].name, albums[i].year, albums[i].artist);
        for (int j = 0; j < albums[i].track_count; j++) {
            printf("\t%d. %s - %d сек. (%s)\n", j + 1, albums[i].a_tracks[j].name, albums[i].a_tracks[j].duration, albums[i].a_tracks[j].genre);
        }
    }
}


void iniz_playlist() {
    static int MAX_PLAYLISTS = 0;
    MAX_PLAYLISTS += 1;

    Playlist* new_playlists = (Playlist*)realloc(playlists, MAX_PLAYLISTS * sizeof(Playlist));
    if (new_playlists == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    playlists = new_playlists;


}

void input_playlist() {

    Playlist new_playlist;
    int count, num;
    printf("Введите название плейлиста: ");
    scanf("%s", new_playlist.name);
    while (getchar() != '\n');
   
    printf("Введите количество треков:\n");

    scanf("%d", &count);
    while (getchar() != '\n');
    printf("Введите номера треков:\n");
    output_track();

    new_playlist.tracks = (Track*)malloc(count * sizeof(Track));
    if (new_playlist.tracks == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        scanf("%d", &num);
        while (getchar() != '\n');
        memcpy(&new_playlist.tracks[i], &tracks[num - 1], sizeof(Track));
    }
    new_playlist.track_count = count;

    playlists[num_playlists] = new_playlist;
    num_playlists += 1;

}

void output_playlist() {

    printf("Список плейлистов:\n");
    for (int i = 0; i < num_playlists; i++) {
        printf("%d. %s\n", i + 1, playlists[i].name);
        for (int j = 0; j < playlists[i].track_count; j++) {
            printf("\t%d. %s - %d сек. (%s)\n", j + 1, playlists[i].tracks[j].name, playlists[i].tracks[j].duration, playlists[i].tracks[j].genre);
        }
    }

}

void iniz_artist() {

    static int MAX_ARTISTS = 0;
    MAX_ARTISTS += 1;

    Artist* new_artists = (Artist*)realloc(artists, MAX_ARTISTS * sizeof(Artist));
    if (new_artists == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    artists = new_artists;

}


void input_artist() {
    Artist new_artist;
    int count;

    printf("Введите имя исполнителя: ");
    scanf("%s", new_artist.name);
    while (getchar() != '\n');

    printf("Введите количество альбомов:\n");
    scanf("%d", &count);
    while (getchar() != '\n');

    new_artist.albums = (Album*)malloc(count * sizeof(Album));
    if (new_artist.albums == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }

    printf("Выберите альбомы для исполнителя %s:\n", new_artist.name);
    output_album();
    for (int i = 0; i < count; i++) {
        int num;
        scanf("%d", &num);
        while (getchar() != '\n');
        memcpy(&new_artist.albums[i], &albums[num - 1], sizeof(Album));
    }
    new_artist.album_count = count;

    artists[num_artists] = new_artist;
    num_artists += 1;
}

void output_artist() {
    printf("Список исполнителей:\n");
    for (int i = 0; i < num_artists; i++) {
        printf("%d. %s\n", i + 1, artists[i].name);
        for (int j = 0; j < artists[i].album_count; j++) {
            printf("\t%d. %s(%d) - %s\n", j + 1, artists[i].albums[j].name, artists[i].albums[j].year, artists[i].albums[j].artist);
            for (int k = 0; k < artists[i].albums[j].track_count; k++) {
                printf("\t\t%d. %s - %d сек. (%s)\n", k + 1, artists[i].albums[j].a_tracks[k].name, artists[i].albums[j].a_tracks[k].duration, artists[i].albums[j].a_tracks[k].genre);
            }
        }
    }

}

void iniz_library() {
    num_libs += 1;

    Library* new_libs = (Library*)realloc(libs, num_libs * sizeof(Library));
    if (new_libs == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    libs = new_libs;
}

void input_library() {
    iniz_library();

    Library new_lib;

    printf("Введите количество альбомов для библиотеки:\n");
    scanf("%d", &new_lib.album_count);
    while (getchar() != '\n');

    new_lib.albums = (Album*)malloc(new_lib.album_count * sizeof(Album));
    printf("Выберите альбомы для библиотеки:\n");
    output_album();
    for (int i = 0; i < new_lib.album_count; i++) {
        int num;
        scanf("%d", &num);
        while (getchar() != '\n');
        memcpy(&new_lib.albums[i], &albums[num - 1], sizeof(Album));
    }

    printf("Введите количество плейлистов для библиотеки:\n");
    scanf("%d", &new_lib.playlist_count);
    while (getchar() != '\n');

    new_lib.playlists = (Playlist*)malloc(new_lib.playlist_count * sizeof(Playlist));
    printf("Выберите плейлисты для библиотеки:\n");
    output_playlist();
    for (int i = 0; i < new_lib.playlist_count; i++) {
        int num;
        scanf("%d", &num);
        while (getchar() != '\n');
        memcpy(&new_lib.playlists[i], &playlists[num - 1], sizeof(Playlist));
    }

    libs[num_libs - 1] = new_lib;
}

void output_library() {
    printf("Список библиотек:\n");
    for (int i = 0; i < num_libs; i++) {
        printf("Библиотека %d:\n", i + 1);

        printf("Альбомы:\n");
        for (int j = 0; j < libs[i].album_count; j++) {
            printf("%d. %s(%d) - %s\n", j + 1, libs[i].albums[j].name, libs[i].albums[j].year, libs[i].albums[j].artist);
            for (int k = 0; k < libs[i].albums[j].track_count; k++) {
                printf("\t%d. %s - %d сек. (%s)\n", k + 1, libs[i].albums[j].a_tracks[k].name, libs[i].albums[j].a_tracks[k].duration, libs[i].albums[j].a_tracks[k].genre);
            }
        }

        printf("Плейлисты:\n");
        for (int j = 0; j < libs[i].playlist_count; j++) {
            printf("%d. %s\n", j + 1, libs[i].playlists[j].name);
            for (int k = 0; k < libs[i].playlists[j].track_count; k++) {
                printf("\t%d. %s - %d сек. (%s)\n", k + 1, libs[i].playlists[j].tracks[k].name, libs[i].playlists[j].tracks[k].duration, libs[i].playlists[j].tracks[k].genre);
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    iniz_track();
    input_track();

    iniz_track();
    input_track();

    output_track();

    iniz_album();
    input_album();
    output_album();

    iniz_playlist();
    input_playlist();
    output_playlist();

    iniz_artist();
    input_artist();
    output_artist();

    input_library();
    output_library();

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