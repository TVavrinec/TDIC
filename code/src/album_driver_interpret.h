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
    parse text, loaded file from file path from parameter, and print album list.
    you can use " ." as default file path "output/album_list.csv"
    you can coll the function from terminal as "load-file <file_path>"
*/
void loadFile_i(char *file_path);

/*
    parse text and deleted album with name from the text
    you can coll the function from terminal as "del-album "
*/
void delAlbum_i(char *album_name);

/*
    parse text and save album list to file on file address in the text 
    the default address is "output/album_list.csv"
    you can coll the function from terminal as "save-album-list <file_path>"
*/
void saveAlbumsList_i(char *file_path);

/*
    print all album
    you can coll the function from terminal as "list "
*/
void printfAllAlbums_i();

/*
    parse text and make a new album with data from text
    data taken in order:
        name interpreter year genre score
    divided by spaces
    you can call the function from a terminal as "add-album <album data>"
*/
void addNewAlbum_i(char *album); 

/*
    parse text and sort album according to "compare_faktor" with the director from "sort_dir".
    compare_factor:
        name
        interpreter
        year
        genre
        score
    sort_dir: defoult is ascending
        VV
    to end, print the album list
    you can call the function from a terminal as "sort-albums <compare_faktor> <sort_dir>"
*/
void sortAlbums_i(char *compare_factor_and_sort_dir);

/*
    print album count
    you can call the function from a terminal as "album-count "
*/
void getAlbumCount_i();

/*
    parse text and print album
    you can call the function from a terminal as "album <name>"
*/
void getAlbum_i(char *name);

/*
    parse text and filter album list.
    the argument is desired values in filtered list in order:
        name interpreter year genre score
    divided by spaces
    if some value is not important you can replace it with "-" symbol.

    for example, you can use the command "filter-album - - - Rock -" to filter Rock albums
    you can call the function from a terminal as "filter-album <filter seting>"
*/
void getAlbumSortedList_i(char *album_prototype);

/*
    parse text and save filtered album list to file on address in the text.
    the default address is "output/filtered_list.csv"
    you can call the function from a terminal as "save-filter <file_path>"
*/
void saveFilteredAlbumList_i(char *file_path);

/*
    parse text and album with entered name.
    the argument is desired values in filtered list in order:
        name interpreter year genre score
    divided by spaces
    if some value is not change you replace it with "-" symbol.

    for example, you can use the command "change-album Vlasy - 2020 - -" to change yer of publication in album "Vlasy"
    you can call the function from a terminal as "change-album <name> <changing param>"
*/
void changeAlbumRecord(char *change_list);

/*
    print all albums in the filtered list
    you can coll the function from terminal as "print-filter "
*/
void printFilteredAlbumList_i();

/*
album_list_t *addNewAlbumToList(album_list_t *prev, album_t *new_album);
void delAlbumFromList(album_list_t *album);

void printFilteredAlbumList(album_list_t *list);
*/