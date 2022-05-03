#include "album_driver_interpret.h"
#include "language.h"

#define SMALL_BUFFER 32

album_t *album_list;

// private ----------------------------------------------------------------
bool readWold(char *buffer, char *word, int *length)
{
    int a = 0;
    for (; (buffer[a] != ' ')&&(a < SMALL_BUFFER); a++) 
    {    
        word[a] = buffer[a];
    }
    word[a] = '\0';
    *length = a;
}

int getComperFaktor(char *compare_faktor)
{
    if(strcmp(compare_faktor, "name")) return albumName;
    if(strcmp(compare_faktor, "interpreter")) return albumInterpreter;
    if(strcmp(compare_faktor, "year")) return albumYear;
    if(strcmp(compare_faktor, "genre")) return albumGenre;
    if(strcmp(compare_faktor, "score")) return albumScore;
    return -1;
}

bool getComperDirectory(char *compare_faktor)
{
    if(strcmp(compare_faktor, "dir-down")) return false;
    return true;
}
// public  ----------------------------------------------------------------
void loadFile_i(char *file_path)
{
    int a;
    for(a = 0; file_path[a]!=';'; a++){}
    file_path[a] = '\0';
    if(strcmp(file_path," ."))
        album_list = loadFile("output/zadani10_databaze.csv");
    else
        album_list = loadFile(file_path);
    if(album_list!=NULL) printfAllAlbums(album_list);
}

void delAlbum_i(char *album_name)
{
    int a;
    for(a = 0; album_name[a]!=';'; a++){}
    album_name[a] = '\0';
    delAlbum(getAlbum(album_list, album_name));
}

void saveAlbumsList_i(char *file_path)
{
    int a;
    for(a = 0; file_path[a]!=';'; a++){}
    file_path[a] = '\0';
    if(!saveAlbumsList(album_list, file_path)) printf("Error saving\n");
}

void printfAllAlbums_i()
{
    printfAllAlbums(album_list);
}

void addNewAlbum_i(char *album)
{
    char *name = (char *)malloc(sizeof(char)*SMALL_BUFFER);
    char *interpreter = (char *)malloc(sizeof(char)*SMALL_BUFFER);
    int year = 0;
    char *genre = (char *)malloc(sizeof(char)*SMALL_BUFFER);
    float score = 0;
    int a = 0;

    for (; (album[a] != ' ')&&(a < SMALL_BUFFER); a++) name[a] = album[a];
    name[a] = '\0';
    a++;
    int b;
    for (b = 0; (album[a] != ' ')&&(b < SMALL_BUFFER); a++) 
    {
        interpreter[b] = album[a];
        b++;
    }
    interpreter[b] = '\0';
    a++;
    readed_number_t x = loadNumber(&album[a]); 
    year = x.value;
    a += x.length+1;

    for (b = 0; (album[a] != ' ')&&(b < SMALL_BUFFER); a++) 
    {
        genre[b] = album[a];
        b++;
    }
    genre[b] = '\0';
    a++;
    x = loadNumber(&album[a]); 
    score = x.value;
    a += x.length+1;
    addNewAlbum(album_list, name, interpreter, year, genre, score);
    free(name);
    free(interpreter);
    free(genre);
}

void sortAlbums_i(char *compare_faktor_and_sort_dir)
{
    char *compare_faktor = (char *)malloc(sizeof(char)*SMALL_BUFFER);
    char *sort_dir = (char *)malloc(sizeof(char)*SMALL_BUFFER);
    int CFASD_position = 0;
    int b = 0;
    for (CFASD_position = 0; (compare_faktor_and_sort_dir[CFASD_position] != ' ')&&(CFASD_position < SMALL_BUFFER); CFASD_position++) compare_faktor[CFASD_position] = compare_faktor_and_sort_dir[CFASD_position];
    compare_faktor[CFASD_position] = '\0';
    CFASD_position++;
    for (b = 0; (compare_faktor_and_sort_dir[CFASD_position] != ' ')&&(b < SMALL_BUFFER); b++) 
    {
        sort_dir[b] = compare_faktor_and_sort_dir[CFASD_position];
        CFASD_position++;
    }
    sort_dir[b] = '\0';
    sortAlbums(album_list, getComperFaktor(compare_faktor), getComperDirectory(sort_dir));
    free(sort_dir);
    free(compare_faktor);
}