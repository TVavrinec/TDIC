#include "album_filter.h"

album_list_t *addNewAlbumToList(album_list_t *prev, album_t *new_album)
{
    album_list_t *new_album_list = (album_list_t *)malloc(sizeof(album_list_t));
    new_album_list->prev = prev;
    new_album_list->next = NULL;
	new_album_list->juicy_kernel = new_album;
	if(prev != NULL) new_album_list->prev->next = new_album_list;
	return new_album_list;
}

void delAlbumFromList(album_list_t *album)
{
    if(album->prev != NULL) album->prev->next = album->next;
	if(album->next != NULL)	album->next->prev = album->prev;
	free(album);
}

bool compareAlbumFactor(album_t *album, album_compare_prototype_t *compare_prototype)
{
    if((compare_prototype->name[0] != '\0')&&(strcmp(compare_prototype->name, album->name))) return false;
    if((compare_prototype->interpreter[0] != '\0')&&(strcmp(compare_prototype->interpreter, album->interpreter))) return false;
    if((compare_prototype->genre[0] != '\0')&&(strcmp(compare_prototype->genre, album->genre))) return false;
    if((compare_prototype->year != -1)&&(compare_prototype->year != album->year)) return false;
    if((compare_prototype->score != -1)&&(compare_prototype->score != album->score)) return false;
    return true;
}

album_list_t *getAlbumSortedList(album_t *album_list, album_compare_prototype_t *album_prototype)
{
    int album_count = getAlbumCount(album_list);
    album_list_t *list = NULL;
    for (int a = 0; (a < album_count)&&(list == NULL); a++)
    {
        if(compareAlbumFactor(album_list, album_prototype)) list = addNewAlbumToList(NULL, album_list);
        album_list = album_list->next;
    }
    while(album_list != NULL) 
    {
        if(compareAlbumFactor(album_list, album_prototype)) addNewAlbumToList( list, album_list);
        album_list = album_list->next;
    }
    return list;
}

void printAlbumList(album_list_t *list)
{
    if(list == NULL)
    {
        printf("filtered album list is empty\n");
        return;
    }
    printf("filtered album list:\n");
   	while(list->next != NULL)
	{
        printf("--> %32s - %25s - %4d - %20s - %5.2f\n", list->juicy_kernel->name, list->juicy_kernel->interpreter, list->juicy_kernel->year, list->juicy_kernel->genre, list->juicy_kernel->score);
        list = list->next;
	}
	printf("--> %32s - %25s - %4d - %20s - %5.2f\n", list->juicy_kernel->name, list->juicy_kernel->interpreter, list->juicy_kernel->year, list->juicy_kernel->genre, list->juicy_kernel->score);
}

bool saveFilteredAlbumList(album_list_t *list, char *file_path)
{
    FILE *file;
	if((file = openFile(file_path, "w"))==NULL) return false;
    if(list == NULL)
    {
        fprintf(file, "filtered album list is empty\n");
        return true;
    }
   	while(list->next != NULL)
	{
        fprintf(file, "%s;%s;%d;%s;%4.2f\n", list->juicy_kernel->name, list->juicy_kernel->interpreter, list->juicy_kernel->year, list->juicy_kernel->genre, list->juicy_kernel->score);
        list = list->next;
	}
	fprintf(file, "%s;%s;%d;%s;%4.2f\n", list->juicy_kernel->name, list->juicy_kernel->interpreter, list->juicy_kernel->year, list->juicy_kernel->genre, list->juicy_kernel->score);
	fclose(file);
    return true;
}


// album_t *giveListInterpreterAlbums(album_t *album_list, char interpreter[20])
// {
//     int album_count = getAlbumCount(album_list);
//     for (int a = 0; a < album_count; a++)
//     {
        
//     }
    
// }

// album_t *giveListGenreAlbums(album_t *album_list, char genre[20]);
// album_t *giveListYearAlbums(album_t *album_list, int year);