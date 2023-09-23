#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define N 50

//int num_tracks = 0;
//Track* tracks = (Track*)malloc(0 * sizeof(Track));
//
//int num_albums = 0;
//Album* albums = (Album*)malloc(0 * sizeof(Album));
//
//int num_playlists = 0;
//Playlist* playlists = (Playlist*)malloc(0 * sizeof(Playlist));
//
//int num_artists = 0;
//Artist* artists = (Artist*)malloc(0 * sizeof(Artist));
//
//int num_libs = 0;
//Library* libs = (Library*)malloc(0 * sizeof(Library));



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

extern int num_tracks;
extern Track* tracks;

extern int num_albums;
extern Album* albums;

extern int num_playlists;
extern Playlist* playlists;

extern int num_artists;
extern Artist* artists;

extern int num_libs;
extern Library* libs;

void iniz_track();
void input_track();
void output_track();

void iniz_album();
void input_album();
void output_album();

void iniz_playlist();
void input_playlist();
void output_playlist();

void iniz_artist();
void input_artist();
void output_artist();

void iniz_library();
void input_library();
void output_library();

void add_track_to_album();
void add_album_to_library();
void search_albums_by_year(int target_year);
void search_tracks_by_genre(char* target_genre);

