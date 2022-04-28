#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "csv_manager.h"

typedef struct album_t album_t;

typedef struct album_t
{
	char name[32];
	char interpreter[32];
	int year;
	char genre[32];
	float score;
	int info;
	album_t *next;
	album_t *prev;
} album_t;

enum album_faktor
{
	albumName,
	albumInterpreter,
	albumYear,
	albumGenre,
	albumScore,
};

//private

//album_t *loadAlbum(album_t *prev, FILE *file);
//int compareAlbums(album_t *a, album_t *b, int compare_faktor, bool sort_dir);
//void controllPrintfAllAlbums(album_t *album);

//public
album_t *loadFile(char *file);
bool saveAlbumsList(album_t *album, char *file_path);

album_t *addNewAlbum(album_t *prev, char *name, char *interpreter, int year, char *genre, float score);
void delAlbum(album_t *album);

album_t *switchAlbums(album_t *a, album_t *b);
album_t *sortAlbums(album_t *first_album, int compare_faktor, bool sort_dir);

void printfAlbum(album_t *album);
void printfAllAlbums(album_t *album);

int getAlbumCount(album_t *album);