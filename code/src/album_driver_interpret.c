#include "album_driver_interpret.h"
#include "language.h"

#define SMALL_BUFFER 32

album_t *album_list;

void loadFile_i(char *file_path)
{
    int a;
    for(a = 0; file_path[a]!=';'; a++){}
    file_path[a] = '\0';
    album_list = loadFile(file_path);
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
}