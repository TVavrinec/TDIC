#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "album_driver.h"
#include "album_filter.h"

void loadFile_i(char *file_path);
void delAlbum_i(char *album_name);
void saveAlbumsList_i(char *file_path);
void printfAllAlbums_i();
void addNewAlbum_i(char *album); //char *name, char *interpreter, int year, char *genre, float score

/*
compare_faktor:
    name
    interpreter
    year
    genre
    score
sort_dir:
    dir-up
    dir-down
*/
void sortAlbums_i(char *compare_faktor_and_sort_dir);

// int getAlbumCount(album_t *album);

// album_t *getAlbum(album_t *album_list, char *name);