#include "album_driver_interpret.h"

#define SMALL_BUFFER 32

album_t *album_list;
album_list_t *album_filtered_list;

// private ----------------------------------------------------------------
bool readWold(char *buffer, char *word, int *length)
{
    if(buffer[0] == ' ') return false;
    int a = 0;
    for (; (!((buffer[a] == ' ')||(buffer[a] == ';')))&&(a < SMALL_BUFFER); a++) 
    {    
        word[a] = buffer[a];
    }
    word[a] = '\0';
    *length += a+1;
    return true;
}

int getComperFaktor(char *compare_faktor)
{
    if(!strcmp(compare_faktor, "name")) return albumName;
    if(!strcmp(compare_faktor, "interpreter")) return albumInterpreter;
    if(!strcmp(compare_faktor, "year")) return albumYear;
    if(!strcmp(compare_faktor, "genre")) return albumGenre;
    if(!strcmp(compare_faktor, "score")) return albumScore;
    return -1;
}

bool getComperDirectory(char *compare_faktor)
{
    if(strcmp(compare_faktor, "VV")) return false;
    return true;
}
// public  ----------------------------------------------------------------
void loadFile_i(char *file_path)
{
    int a;
    for(a = 0; file_path[a]!=';'; a++){}
    file_path[a] = '\0';
    if(strcmp(file_path," ."))
        album_list = loadFile("output/album_list.csv");
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
    if(file_path[0]=='.')
    {
        if(!saveAlbumsList(album_list, "output/album_list.csv")) printf("\033[0;31mError saving\033[0;37m\n");
        return;
    }
    int a;
    for(a = 0; file_path[a]!=';'; a++){}
    file_path[a] = '\0';
    if(!saveAlbumsList(album_list, file_path)) printf("\033[0;31mError saving\033[0;37m\n");
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

    int album_position = 0;
    readWold(&album[album_position], name, &album_position);
    readWold(&album[album_position], interpreter, &album_position);
    readed_number_t x = loadNumber(&album[album_position]); 
    year = x.value;
    album_position += x.length+1;
    readWold(&album[album_position], genre, &album_position);
    score = loadNumber(&album[album_position]).value; 
    printfAlbum(addNewAlbum(album_list, name, interpreter, year, genre, score));

    free(name);
    free(interpreter);
    free(genre);
}

void sortAlbums_i(char *compare_faktor_and_sort_dir)
{
    char *compare_faktor = (char *)malloc(sizeof(char)*SMALL_BUFFER);
    char *sort_dir = (char *)malloc(sizeof(char)*SMALL_BUFFER);
    int CFASD_position = 0;
    readWold(&compare_faktor_and_sort_dir[CFASD_position], compare_faktor, &CFASD_position);
    readWold(&compare_faktor_and_sort_dir[CFASD_position], sort_dir,       &CFASD_position);
    album_list = sortAlbums(album_list, getComperFaktor(compare_faktor), getComperDirectory(sort_dir));
    printfAllAlbums(album_list);
    free(sort_dir);
    free(compare_faktor);
}

void getAlbumCount_i()
{
    printf("Album count: %d\n",getAlbumCount(album_list));
}

void getAlbum_i(char *name)
{
    int a;
    for(a = 0; name[a]!=';'; a++){}
    name[a] = '\0';
    printfAlbum(getAlbum(album_list, name));
}

void getAlbumSortedList_i(char *album_prototype)
{
    char *name        = (char *)malloc(sizeof(char)*SMALL_BUFFER);
    char *interpreter = (char *)malloc(sizeof(char)*SMALL_BUFFER);
    char *year        = (char *)malloc(sizeof(char)*SMALL_BUFFER);
    char *genre       = (char *)malloc(sizeof(char)*SMALL_BUFFER);
    char *score       = (char *)malloc(sizeof(char)*SMALL_BUFFER);
    album_compare_prototype_t filter_prototype;
    int album_prototype_position = 0;

    readWold(&album_prototype[album_prototype_position], name         , &album_prototype_position);
    readWold(&album_prototype[album_prototype_position], interpreter  , &album_prototype_position);
    readWold(&album_prototype[album_prototype_position], year         , &album_prototype_position);
    readWold(&album_prototype[album_prototype_position], genre        , &album_prototype_position);
    readWold(&album_prototype[album_prototype_position], score        , &album_prototype_position);
    
    if(name       [0]!='-') strcpy(filter_prototype.name       , name       ); else filter_prototype.name       [0] = '\0';
    if(interpreter[0]!='-') strcpy(filter_prototype.interpreter, interpreter); else filter_prototype.interpreter[0] = '\0';
    if(genre      [0]!='-') strcpy(filter_prototype.genre      , genre      ); else filter_prototype.genre      [0] = '\0';
    if(year       [0]!='-') filter_prototype.year  = atof(year )             ; else filter_prototype.year           = -1;
    if(score      [0]!='-') filter_prototype.score = atof(score)             ; else filter_prototype.score          = -1;

    album_filtered_list = getAlbumSortedList(album_list, &filter_prototype);
    printAlbumList(album_filtered_list);
    
    free(name);
    free(interpreter);
    free(year);
    free(genre);
    free(score);   
}

void saveFilteredAlbumList_i(char *file_path)
{
    if(file_path[0]=='.')
    {
        if(!saveAlbumsList(album_list, "output/filtered_list.csv")) printf("\033[0;31mError saving\033[0;37m\n");
        return;
    }
    int a;
    for(a = 0; file_path[a]!=';'; a++){}
    file_path[a] = '\0';
    if(!saveFilteredAlbumList(album_filtered_list, file_path)) printf("\033[0;31mError saving\033[0;37m\n");
}