Popis databázových terminálových funkcí
=======================================

Private funkce
--------------

``` {style="CStyle"}
bool readWold(char *buffer, char *word, int *length);
int getComperFaktor(char *compare_faktor);
bool getComperDirectory(char *compare_faktor);
```

Tyto funkce slouží pro zvýšení přehlednosti kódu a jejich název je podle
mě plně vystihuje.

Public funkce
-------------

``` {style="CStyle"}
/*
    parse text, loaded file from file path from parameter, and print album list.
    you can use " ." as default file path "output/album_list.csv"
    you can coll the function from terminal as "load-file <file_path>"
*/
void loadFile_i(char *file_path);
```

Načte databázi ze souboru na adrese zadané v předané textu, který
nejprve zkontroluje. Pro pohodlnost můžete využívat výchozí soubor na
adrese \"output/album\_list.csv\" pomocí parametru \" .\".\
Příklad volání: \"load-file output/album\_list.csv\" nebo \"load-file
.\"

``` {style="CStyle"}
/*
    parse text and deleted album with name from the text
    you can coll the function from terminal as "del-album "
*/
void delAlbum_i(char *album_name);
```

Vymaže z databáze album jehož jméno jste zadali\
Příklad volání: \"del-album Vlasy\" pro smazání alba s názvem Vlasy.

``` {style="CStyle"}
/*
    parse text and save album list to file on file address in the text 
    the default address is "output/album_list.csv"
    you can coll the function from terminal as "save-album-list <file_path>"
*/
void saveAlbumsList_i(char *file_path);
```

Uloží databázi do souboru na zadané adrese. Opět můžete využít \" .\"
namísto zdlouhavého \"output/album\_list.csv\".\
Příklad volání: \"save-album-list output/album\_list.csv\" nebo
\"save-album-list .\"

``` {style="CStyle"}
/*
    print all album
    you can coll the function from terminal as "list "
*/
void printfAllAlbums_i();
```

Vypíše všechna alba v databázi.\
Příklad volání: \"list\".

``` {style="CStyle"}
/*
    parse text and make a new album with data from text
    data taken in order:
    name interpreter year genre score
    divided by spaces
    you can call the function from a terminal as "add-album <album data>"
*/
void addNewAlbum_i(char *album); 
```

Vytvoří nové album z předaných parametrů.\
Příklad volání: \"add-album jmeno interpret 2010 zanr 8\" pro vytvoření
alba se jménem \"jmeno\" od autora \"interpret\" z roku \"2010\" žánru
\"zanr\" a hodnocením 8.

``` {style="CStyle"}
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
```

Seřadí alba podle zadaného parametru, ve výchozím stavu vzestupně a při
zadání přepínače \"VV\" sestupně. Parametr lze zadat klíčovými slovy
\"name\", \"interpreter\", \"year\", \"genre\" a \"score\".\
Příklad volání: \"sort-albums score\" pro seřazení alb podle jejich
hodnocení.

``` {style="CStyle"}
/*
    print album count
    you can call the function from a terminal as "album-count "
*/
void getAlbumCount_i();
```

Spočítá alba v databázi a vypíše jejich počet.\
Příklad volání: \"album-count\".

``` {style="CStyle"}
/*
    parse text and print album
    you can call the function from a terminal as "album <name>"
*/
void getAlbum_i(char *name);
```

Vypíše záznam o albu zadaného jména. Předpokládá že jméno slouží jako
jednoznační identifikátor alba.\
Příklad volání: \"album Vlasy\" pro výpis záznamu o albu Vlasy.

``` {style="CStyle"}
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
```

Vyfiltruje alba jejichž položky odpovídají zadaným. Pokud je třeba
filtrovat jen podle některých položek zadejte místo položek nevyužitých
\"-\". Všechny parametry musí být vždy odděleny mezerou.\
Příklad volání: \"filter-album - - 2003 - -\" pro vyfiltrovat všech alb
z roku 2003.

``` {style="CStyle"}
/*
    parse text and save filtered album list to file on address in the text.
    the default address is "output/filtered_list.csv"
    you can call the function from a terminal as "save-filter <file_path>"
*/
void saveFilteredAlbumList_i(char *file_path);
```

Uloží vyfiltrovaná alba do souboru který je předán v parametru. Opět vze
použít \".\" namísto \"output/filtered\_list.csv\" jakožto výchozí
soubor.\
Příklad volání: \"save-filter output/filtered\_list.csv\" nebo
\"save-filter .\".

``` {style="CStyle"}
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
```

Přepíše kteroukoli položku alba krom jména alba, podle kterého
identifikuje upravované album. Parametru které mají zůstat stejné budou
nahrazeny pomlčkou \"-\".\
Příklad volání: \"change-album Vlasy - - - 8\" pro změnu původního
hodnocení alba \"Vlasy\" na hodnocení 8.

``` {style="CStyle"}
/*
    print all albums in the filtered list
    you can coll the function from terminal as "print-filter "
*/
void printFilteredAlbumList_i();
```

Vypíše všechna alba která která jsou aktuálně vyfiltrovaná.\
Příklad volání: \"print-filter \".
