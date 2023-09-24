#include "Header.h"

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
    iniz_track();
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
    iniz_album();
    if (num_tracks == 0) {
        printf("Недостаточно треков");
        return;
    }
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
    do {
        printf("Введите количество треков:\n");

        scanf("%d", &count);
        if (count > num_tracks) {
            printf("Нет столько треков");
        }
        while (getchar() != '\n');
    } while (count > num_tracks);
 
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
    iniz_playlist();
    if (num_tracks == 0) {
        printf("Недостаточно треков");
        return;
    }
    Playlist new_playlist;
    int count, num;
    printf("Введите название плейлиста: ");
    scanf("%s", new_playlist.name);
    while (getchar() != '\n');

    do {
        printf("Введите количество треков:\n");

        scanf("%d", &count);
        while (getchar() != '\n');

        if (num_tracks < count) {
            printf("Ошибка");
        }
    } while (num_tracks < count);
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
    iniz_artist();
    if (num_albums == 0) {
        printf("Ошибка");
        return;
    }
    Artist new_artist;
    int count;

    printf("Введите имя исполнителя: ");
    scanf("%s", new_artist.name);
    while (getchar() != '\n');

    do {
        printf("Введите количество альбомов:\n");
        scanf("%d", &count);
        while (getchar() != '\n');
    } while (count>num_albums);
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
    if (num_albums == 0 || num_playlists == 0) {
        return;
    }
    Library new_lib;

    do {
        printf("Введите количество альбомов для библиотеки:\n");
        scanf("%d", &new_lib.album_count);
        while (getchar() != '\n');
    } while (new_lib.album_count > num_albums);

    new_lib.albums = (Album*)malloc(new_lib.album_count * sizeof(Album));
    printf("Выберите альбомы для библиотеки:\n");
    output_album();
    for (int i = 0; i < new_lib.album_count; i++) {
        int num;
        scanf("%d", &num);
        while (getchar() != '\n');
        memcpy(&new_lib.albums[i], &albums[num - 1], sizeof(Album));
    }

    do {
        printf("Введите количество плейлистов для библиотеки:\n");
        scanf("%d", &new_lib.playlist_count);
        while (getchar() != '\n');
    } while (new_lib.playlist_count > num_playlists);

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

void add_track_to_album() {
    printf("Выберите альбом для добавления трека:\n");
    output_album();
    int album_num;
    scanf("%d", &album_num);
    while (getchar() != '\n');

    Album* album = &albums[album_num - 1];

    printf("Выберите трек для добавления в альбом:\n");
    output_track();
    int track_num;
    scanf("%d", &track_num);
    while (getchar() != '\n');

    Track* track = &tracks[track_num - 1];

    // проверка наличия трека в списке треков альбома
    for (int i = 0; i < album->track_count; i++) {
        if (strcmp(album->a_tracks[i].name, track->name) == 0) {
            printf("Трек уже есть в альбоме!\n");
            return;
        }
    }

    album->track_count += 1;
    Track* new_tracks = (Track*)realloc(album->a_tracks, album->track_count * sizeof(Track));
    if (new_tracks == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    album->a_tracks = new_tracks;
    Track* new_track = &album->a_tracks[album->track_count - 1];
    strcpy(new_track->name, track->name);
    new_track->duration = track->duration;
    strcpy(new_track->genre, track->genre);

    printf("Трек успешно добавлен в альбом!\n");
}


void add_album_to_library() {
    printf("Выберите библиотеку для добавления альбома:\n");
    output_library();
    int lib_num;
    scanf("%d", &lib_num);
    while (getchar() != '\n');

    Library* lib = &libs[lib_num - 1];

    printf("Выберите альбом для добавления в библиотеку:\n");
    output_album();
    int album_num;
    scanf("%d", &album_num);
    while (getchar() != '\n');

    Album* album = &albums[album_num - 1];

    // проверка наличия альбома в списке альбомов библиотеки
    for (int i = 0; i < lib->album_count; i++) {
        if (strcmp(lib->albums[i].name, album->name) == 0 && strcmp(lib->albums[i].artist, album->artist) == 0) {
            printf("Альбом уже есть в библиотеке!\n");
            return;
        }
    }

    lib->album_count += 1;
    Album* new_albums = (Album*)realloc(lib->albums, lib->album_count * sizeof(Album));
    if (new_albums == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    lib->albums = new_albums;
    Album* new_album = &lib->albums[lib->album_count - 1];

    new_album->track_count = album->track_count;
    new_album->a_tracks = (Track*)malloc(new_album->track_count * sizeof(Track));
    if (new_album->a_tracks == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }

    strcpy(new_album->name, album->name);
    strcpy(new_album->artist, album->artist);
    new_album->year = album->year;
    for (int i = 0; i < new_album->track_count; i++) {
        strcpy(new_album->a_tracks[i].name, album->a_tracks[i].name);
        new_album->a_tracks[i].duration = album->a_tracks[i].duration;
        strcpy(new_album->a_tracks[i].genre, album->a_tracks[i].genre);
    }

    printf("Альбом успешно добавлен в библиотеку!\n");
}

void search_albums_by_year(int target_year) {
    int found_albums = 0;

    printf("Альбомы, выпущенные в %d году:\n", target_year);
    for (int i = 0; i < num_albums; i++) {
        if (albums[i].year == target_year) {
            printf("%d. %s - %s\n", i + 1, albums[i].name, albums[i].artist);
            found_albums++;
        }
    }

    if (found_albums == 0) {
        printf("Не найдено альбомов, выпущенных в %d году.\n", target_year);
    }
}

void search_tracks_by_genre(char* target_genre) {
    int found_tracks = 0;

    printf("Треки жанра \"%s\":\n", target_genre);
    for (int i = 0; i < num_tracks; i++) {
        if (strcmp(tracks[i].genre, target_genre) == 0) {
            printf("%d. %s - %s (%d)\n", i + 1, tracks[i].name, tracks[i].genre, tracks[i].duration);
            found_tracks++;
        }
    }

    if (found_tracks == 0) {
        printf("Не найдено треков жанра \"%s\".\n", target_genre);
    }
}

void del_track_from_album(char* track_name, char* album_name) {
    for (int i = 0; i < num_albums; i++) {
        if (strcmp(albums[i].name, album_name) == 0) {
            int j;
            for (j = 0; j < albums[i].track_count; j++) {
                if (strcmp(albums[i].a_tracks[j].name, track_name) == 0) {
                    break;
                }
            }

            if (j < albums[i].track_count) {
                for (int k = j; k < albums[i].track_count - 1; k++) {
                    albums[i].a_tracks[k] = albums[i].a_tracks[k + 1];
                }

                albums[i].track_count--;
                albums[i].a_tracks = (Track*)realloc(albums[i].a_tracks, albums[i].track_count * sizeof(Track));
                printf("Трек \"%s\" был удален из альбома \"%s\".\n", track_name, album_name);
            }
            else {
                printf("Трек \"%s\" не найден в альбоме \"%s\".\n", track_name, album_name);
            }

            break;
        }
    }
}

void clean_tracks() {
    free(tracks);

}
void clean_albums() {
    for (int i = 0; i < num_albums; i++) {
        free(albums[i].a_tracks);
    }

    free(albums);

}
void clean_playlists() {
    for (int i = 0; i < num_playlists; i++) {
        free(playlists[i].tracks);
    }
    free(playlists);

}
void clean_artists() {
    for (int i = 0; i < num_artists; i++) {
        free(artists[i].albums);
    }
    free(artists);

}
void clean_libs() {
    for (int i = 0; i < num_libs; i++) {

        if (libs[i].albums != NULL) {
            free(libs[i].albums);
        }
        if (libs[i].playlists != NULL) {
            free(libs[i].playlists);

        }
    }
    free(libs);

}