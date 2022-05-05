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


/*
	this is enum primer for "compare factor" in function "sortAlbums"
*/
typedef enum 
{
	albumName,
	albumInterpreter,
	albumYear,
	albumGenre,
	albumScore,
} album_factor;

//private

//album_t *loadAlbum(album_t *prev, FILE *file);
//int compareAlbums(album_t *a, album_t *b, int compare_faktor, bool sort_dir);
//void controllPrintfAllAlbums(album_t *album);

//public
/*
	load file .csv on address file_path to memory and return address to the first member of the list from the file 
    if the file non exist return NULL
*/
album_t *loadFile(char *file_path);

/*
	save album "album" list to file on address file_path 
*/
bool saveAlbumsList(album_t *album, char *file_path);

/*
	add new album to album list "album" with name "name", interpreter "interpreter", year "year", genre "genre", score "score"
	return pointier to the new album
*/
album_t *addNewAlbum(album_t *album_list, char *name, char *interpreter, int year, char *genre, float score);

/*
	remove album on address "album" from the album list and deleted it
*/
void delAlbum(album_t *album);

/*
    flip order of albums "a" and "b"
*/
album_t *switchAlbums(album_t *a, album_t *b);

/*
	sort album according to "compare_faktor" in order "sort_dir" 
	you can us enum compare_faktor:
        name		= 0
        interpreter = 1
        year		= 2
        genre		= 3
        score		= 4
*/
album_t *sortAlbums(album_t *first_album, album_factor compare_factor, bool sort_dir);

/*
	print album on address "album"
*/
void printfAlbum(album_t *album);

/*
    print all albums in list start it on address "album_list"
*/
void printfAllAlbums(album_t *album_list);

/*
    calculate the count of albums in the list starting with address "album"
*/
int getAlbumCount(album_t *album_list);

/*
	return address to the album with a name "name" from the album list "album list"
*/
album_t *getAlbum(album_t *album_list, char *name);