#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "language.h"
#include "album_driver.h"
#include "album_filter.h"

// private ----------------------------------------------------------------
/* 
bool readWold(char *buffer, char *word, int *length);
int getComperFaktor(char *compare_faktor);
bool getComperDirectory(char *compare_faktor);
*/

// public  ----------------------------------------------------------------
/*
    parse text, loaded file from file path from parameter and printf album list.
    " ." is default file path "output/album_list.csv"
*/
void loadFile_i(char *file_path);

/*
    parse text and deleted album with name from text
*/
void delAlbum_i(char *album_name);

/*
    parse text and save album list to file on file address in text 
    default address is "output/album_list.csv"
*/
void saveAlbumsList_i(char *file_path);

/*
    printf all album
*/
void printfAllAlbums_i();

/*
    parse text and make a new album with data from text
*/
void addNewAlbum_i(char *album); //char *name, char *interpreter, int year, char *genre, float score

/*
    parse text and sort album according to compare_faktor with directori from sort_dir.
    compare_faktor:
        name
        interpreter
        year
        genre
        score
    sort_dir: defoult is ascending
        VV
    to end, printf album list
*/
void sortAlbums_i(char *compare_faktor_and_sort_dir);

/*
    printf album count
*/
void getAlbumCount_i();

/*
    parse text and printf album
*/
void getAlbum_i(char *name);

/*
    parse text and filter album list.
    argument is desired values in filtered list in order:
        name interpreter year genre score
    divided by spaces
    if some value is not important you can replase it with "-" simbol.

    for example you can use command "filter-album - - - Rock -" for filter Rock albums
*/
void getAlbumSortedList_i(char *album_prototype);

/*
    parse text and save filtered album list to file on address in text 
    default address is "output/filtered_list.csv"
*/
void saveFilteredAlbumList_i(char *file_path);

/*
album_list_t *addNewAlbumToList(album_list_t *prev, album_t *new_album);
void delAlbumFromList(album_list_t *album);

void printFilteredAlbumList(album_list_t *list);
void printAlbumList(album_list_t *list);
*/