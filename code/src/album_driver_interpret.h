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


// album_t *addNewAlbum(album_t *prev, char *name, char *interpreter, int year, char *genre, float score);

// album_t *switchAlbums(album_t *a, album_t *b);
// album_t *sortAlbums(album_t *first_album, int compare_faktor, bool sort_dir);

// void printfAlbum(album_t *album);

// int getAlbumCount(album_t *album);

// album_t *getAlbum(album_t *album_list, char *name);