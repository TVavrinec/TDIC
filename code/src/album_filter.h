#pragma once
#include "album_driver.h"

typedef struct album_list_t album_list_t;

typedef struct album_list_t
{
	album_list_t *next;
	album_t	*juicy_kernel;
	album_list_t *prev;
}album_list_t;

typedef struct album_compare_prototype_t
{
    char name[20];
	char interpreter[20];
	int year;
	char genre[20];
	float score;
} album_compare_prototype_t;

//private

//bool compareAlbumFactor(album_t *album, album_compare_prototype_t *compare_prototype);

//public

album_list_t *addNewAlbumToList(album_list_t *prev, album_t *new_album);
void delAlbumFromList(album_list_t *album);

album_list_t *getAlbumSortedList(album_t *album_list, album_compare_prototype_t *album_prototype);

void printFilteredAlbumList(album_list_t *list);
bool saveFilteredAlbumList(album_list_t *list, char *file_path);
void printAlbumList(album_list_t *list);

// album_list_t *giveListInterpreterAlbums(album_t *album_list, char interpreter[20]);
// album_list_t *giveListGenreAlbums(album_t *album_list, char genre[20]);
// album_list_t *giveListYearAlbums(album_t *album_list, int year);