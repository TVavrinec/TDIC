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

/*
	add a new album to a virtual album list.
	the virtual album list is only a list of pointier to album in album list composite from album_t structs
*/
album_list_t *addNewAlbumToList(album_list_t *prev, album_t *new_album);

/*
    remove album on address "album" from his virtual album list and deleted it
*/
void delAlbumFromList(album_list_t *album);

/*
	filter album corresponding with "album_prototype"
	if some text value is not important write in '\0'
	if some number value is not important write in -1
*/
album_list_t *getAlbumSortedList(album_t *album_list, album_compare_prototype_t *album_prototype);

/*
	print all album in virtual album list
*/
void printFilteredAlbumList(album_list_t *list);

/*
    save all albums in virtual album list to file on address "file_path"
*/
bool saveFilteredAlbumList(album_list_t *list, char *file_path);