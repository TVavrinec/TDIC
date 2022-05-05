Vzhled a základní funkce databáze
=================================

Každý záznam o albu je realizován pomocí struktury \"album\_t\", která
nese informaci o názvu\"char name\[32\]\", autorovy \"char
interpreter\[32\]\", roku vydání \"int year\", žánru \"char
genre\[32\]\", hodnocení \"float score\" a ukazatel na předchozí a
následující album v lineárním seznamu.

``` {style="CStyle"}
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
```

Private funkce databáze
-----------------------

``` {style="CStyle"}
album_t *loadAlbum(album_t *prev, FILE *file);
int compareAlbums(album_t *a, album_t *b, int compare_faktor, bool sort_dir);
void controllPrintfAllAlbums(album_t *album);
```

Public funkce databáze
----------------------

``` {style="CStyle"}
/*
    load file .csv on address file_path to memory and return address to the 
    first member of the list from the file 
    if the file non exist return NULL
*/
album_t *loadFile(char *file_path);
```

Načte databázi ze souboru na adrese \"file\_path\" a vrátí ukazatel na
první prvek této databáze. Pokud soubor neexistuje nebo z jiného důvodu
nejde otevřít, vypíše do konzole \"Error!!! the file
$\backslash$\"%s$\backslash$\" does not exist or is not readable\" a
vrátí NULL.

``` {style="CStyle"}
/*
    save album "album" list to file on address file_path 
*/
bool saveAlbumsList(album_t *album, char *file_path);
```

Uloží databázi do souboru na adrese \"file\_path\" ve formátu csv.

``` {style="CStyle"}
/*
    add new album to album list "album" with name "name", interpreter "interpreter",
    year "year", genre "genre", score "score"
    return pointier to the new album
*/
album_t *addNewAlbum(album_t *album_list, char *name, char *interpreter, int year, 
             char *genre, float score);
```

Vytvoří nové album a zařadí ho na konec lineárního seznamu na adrese
\"album\_list\". Vrací ukazatel na nové album.

``` {style="CStyle"}
/*
    remove album on address "album" from the album list and deleted it
*/
void delAlbum(album_t *album);
```

Odstraní album na adrese \"album\" z lineárního seznamu a následně
uvolní jeho paměť.

``` {style="CStyle"}
/*
    flip order of albums "a" and "b"
*/
album_t *switchAlbums(album_t *a, album_t *b);
```

Prohodí pořadí alb \"a\" a \"b\" v lineárním seznamu.

``` {style="CStyle"}
/*
    sort album according to "compare_faktor" in order "sort_dir" 
    you can us enum compare_faktor:
        name        = 0
        interpreter = 1
        year        = 2
        genre       = 3
        score       = 4
*/
album_t *sortAlbums(album_t *first_album, album_factor compare_factor, bool sort_dir);
```

Seřadí databázi podle položky předané v parametru \"compare\_factor\" ve
směru určeném parametrem \"sort\_dir\". Pro určení \"compare\_factor\"
můžete využít enum \"album\_factor\".

``` {style="CStyle"}
typedef enum
{
    albumName,
    albumInterpreter,
    albumYear,
    albumGenre,
    albumScore,
} album_factor;
```

``` {style="CStyle"}
/*
    print album on address "album"
*/
void printfAlbum(album_t *album);
```

Vytiskne do konzole album na adrese \"album\".

``` {style="CStyle"}
/*
    print all albums in list start it on address "album"
*/
void printfAllAlbums(album_t *album_list);
```

Vytiskne do konzole všechna alba ze seznamu začínajícího na adrese
\"album\_list\".

``` {style="CStyle"}
/*
    calculate the count of albums in the list starting with address "album_list"
*/
int getAlbumCount(album_t *album_list);
```

Vrátí počet alb v seznamu na adrese \"album\_list\"

``` {style="CStyle"}
/*
    return address to the album with a name "name" from the album list "album list"
*/
album_t *getAlbum(album_t *album_list, char *name);
```

Vrátí ukazatel na album s názvem \"name\".
