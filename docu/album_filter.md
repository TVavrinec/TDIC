Filtrování alb
==============

Private funkce filtru
---------------------

``` {style="CStyle"}
bool compareAlbumFactor(album_t *album, album_compare_prototype_t *compare_prototype);
```

Porovná alba na adrese \"album\" s prototypem
\"album\_compare\_prototype\_t\" na adrese \"compare\_prototype\". V
prototypu jsou zapsány hodnoty všech faktorů alba, pokud se některý
faktor porovnávat nemá, v prototypu bude v dané složce '$\backslash$0'
pro text a -1 pro číslo.

Funkce pro použití mimo knihovnu
--------------------------------

``` {style="CStyle"}
/*
    add a new album to a virtual album list.
    the virtual album list is only a list of pointier to album in album list composite 
    from album_t structs
*/
album_list_t *addNewAlbumToList(album_list_t *prev, album_t *new_album);
```

Přidá strukturu \"album\_list\_t\" do lineárního seznamu. Struktura
\"album\_list\_t\" obsahující ukazatele na album uložená v lineárním
seznamu složeném ze struktur \"album\_t\". Dále obsahuje ukazatel na
předchozí a následující položku seznamu.

``` {style="CStyle"}
/*
    remove album on address "album" from his virtual album list and deleted it
*/
void delAlbumFromList(album_list_t *album);
```

Smaže album na adrese \"album\" z filtrovaného seznamu.

``` {style="CStyle"}
/*
    filter album corresponding with "album_prototype"
    if some text value is not important write in '\0'
    if some number value is not important write in -1
*/
album_list_t *getAlbumSortedList(album_t *album_list, 
                                 album_compare_prototype_t *album_prototype);
```

Vyfiltruje všechna alba odpovídající prototypu, vytvoří z nich lineární
seznam a vrátí ukazatel na první prvek tohoto seznamu. V prototypu jsou
zapsány hodnoty všech faktorů alba, pokud je pro filtraci nějaký faktor
nepodstatný bude v dané složce prototypu \"$\backslash$0\" pro text a -1
pro číslo.

``` {style="CStyle"}
/*
    print all album in virtual album list
*/
void printFilteredAlbumList(album_list_t *list);
```

Vytiskne do konzole všechna alba z filtrovaného seznamu na adrese
\"list\".

``` {style="CStyle"}
/*
    save all albums in virtual album list to file on address "file_path"
*/
bool saveFilteredAlbumList(album_list_t *list, char *file_path);
```

uloží do souboru na adrese \"fil0e\_path\" všechna alba z filtrovaného
seznamu na adrese \"list\".
