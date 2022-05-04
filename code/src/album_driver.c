#include "album_driver.h"

//private ********************************************************************************************************************************************************

album_t *loadAlbum(album_t *prev, FILE *file,char *file_path)
{
	if((prev!=NULL) && (prev->info == endFile))
	{
		printf("\nEnd of file %s\n", file_path);
		return NULL;
	}
	album_t *new_album  = (album_t *)malloc(sizeof(album_t));
	new_album->next = NULL;
	strcpy(new_album->name, readFileCell(file).text);
	strcpy(new_album->interpreter, readFileCell(file).text);
	new_album->year = readFileCell(file).number;
	strcpy(new_album->genre, readFileCell(file).text);
	cell_t call = readFileCell(file);
	new_album->score = call.number;
	new_album->prev = prev;
	if(prev != NULL)	prev->next = new_album;

	if(call.index == endFile)	new_album->info = endFile;
	return new_album;
}

// int compareAlbums(album_t *a, album_t *b, int compare_faktor)
// {
// 	int i = 0;
// 	if(a == NULL) return false;
// 	if(b == NULL) return false;

// 	switch (compare_faktor)
// 	{
// 	case albumName:
// 		while(a->name[i] == b->name[i])i++;
// 		return (a->name[i] < b->name[i]) ? true : false;
// 		break;
// 	case albumInterpreter:
// 		while(a->interpreter[i] == b->interpreter[i])i++;
// 		return (a->interpreter[i] < b->interpreter[i]) ? true : false;
// 		break;
// 	case albumYear:
// 		return (a->year < b->year) ? true : false;
// 		break;
// 	case albumGenre:
// 		while(a->genre[i] == b->genre[i])i++;
// 		return (a->genre[i] < b->genre[i]) ? true : false;
// 		break;
// 	case albumScore:
// 		return (a->score < b->score) ? true : false;
// 		break;
// 	default:
// 		return -1;
// 		break;
// 	}
// }

int compareAlbums(album_t *a, album_t *b, int compare_faktor, bool sort_dir)
{
	int i = 0;
	if(a == NULL) return false;
	if(b == NULL) return false;

	switch (compare_faktor)
	{
	case albumName:
		while(a->name[i] == b->name[i])i++;
		return (a->name[i] < b->name[i]) ? sort_dir : !sort_dir;
		break;
	case albumInterpreter:
		while(a->interpreter[i] == b->interpreter[i])i++;
		return (a->interpreter[i] < b->interpreter[i]) ? sort_dir : !sort_dir;
		break;
	case albumYear:
		return (a->year < b->year) ? sort_dir : (a->year == b->year) ? false : !sort_dir;
		break;
	case albumGenre:
		while(a->genre[i] == b->genre[i])i++;
		return (a->genre[i] < b->genre[i]) ? sort_dir : !sort_dir;
		break;
	case albumScore:
		return (a->score < b->score) ? sort_dir : (a->score == b->score) ? false : !sort_dir;
		break;
	default:
		return -1;
		break;
	}
}

//public ********************************************************************************************************************************************************

album_t *addNewAlbum(album_t *album, char *name, char *interpreter, int year, char *genre, float score)
{
	album_t *prev = album->next;
	while(prev->next != NULL)
	{
		prev = prev->next;
	}
	album_t *new_album = (album_t *)malloc(sizeof(album_t));
	new_album->next = NULL;
	strcpy(new_album->name, name);
	strcpy(new_album->interpreter, interpreter);
	new_album->year = year;
	strcpy(new_album->genre, genre);
	new_album->score = score;

	new_album->info = new;
	new_album->prev = prev;
	if(prev != NULL) prev->next = new_album;
	return new_album;
}

void delAlbum(album_t *album)
{
	if(album == NULL) return;
	if(album->prev != NULL) album->prev->next = album->next;
	if(album->next != NULL)	album->next->prev = album->prev;
	free(album);
}

album_t *loadFile(char *file_path)
{
	FILE *file = openFile(file_path, "r");
	album_t *frst_album = loadAlbum(NULL, file, file_path);
	album_t *new_album = frst_album;
	while(new_album->info != endFile)
	{
		new_album = loadAlbum(new_album, file, file_path);
	}
	fclose(file);
	return frst_album;
}


album_t *switchAlbums(album_t *a, album_t *b)
{
	// printf("\n--->%p - %p\n",b->prev, a->prev);
	if(a->prev != NULL) a->prev->next = a->next;
	if(b->next != NULL) b->next->prev = b->prev;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
	return a;
}

int getAlbumCount(album_t *album)
{
	int count = 1;
	while(album->next != NULL)
	{
		count++;
		album = album->next;
	}
	return count;
}

void controllPrintfAllAlbums(album_t *album)
{
	while(album->next != NULL)
	{
		printf("next %15p - prev %15p\n", album->next, album->prev);
		album = album->next;
	}
	printf("next %15p - prev %15p\n\n", album->next, album->prev);
}

album_t *sortAlbums(album_t *first_album, int compare_faktor, bool sort_dir)
{
	album_t *album = first_album;
	int switch_count = 1;
	while(switch_count!=0)
	{
		switch_count = 0;
		first_album = (compareAlbums(first_album,first_album->next, compare_faktor, sort_dir)==1) ? switchAlbums(first_album, first_album->next)->prev : first_album;
		album = first_album->next;
		while(album->next!=NULL)
		{
			if(compareAlbums(album,album->next, compare_faktor, sort_dir)==1)
			{
				album = switchAlbums(album, album->next);
				switch_count++;
			}
			else
				album = album->next;
		}
	}
	return first_album;
}

bool saveAlbumsList(album_t *album, char *file_path)
{
	FILE *file;
	if((file = openFile(file_path, "w"))==NULL) return false;
	while(album->next != NULL)
	{
		fprintf(file, "%s;%s;%d;%s;%f\n", album->name, album->interpreter, album->year, album->genre, album->score);
		album = album->next;
	}
	fprintf(file, "%s;%s;%d;%s;%f", album->name, album->interpreter, album->year, album->genre, album->score);
	fclose(file);
	return true;
}

void printfAlbum(album_t *album)
{
	printf("\033[4m%36s - %25s - %4d - %20s -", album->name, album->interpreter, album->year, album->genre);
	(album->score<3) ? printf("\033[0;33m\033[4m %5.2f\n\n", album->score) : (album->score<8)? printf("\033[0;32m\033[4m %5.2f\n", album->score) : printf("\033[0;31m\033[4m %5.2f\n", album->score);
}

void printfAllAlbums(album_t *album)
{
    printf("\033[4m                                                                                                      \n");
	while(album->next != NULL)
	{
		printf("%36s | %25s | %4d | %20s |", album->name, album->interpreter, album->year, album->genre);
		(album->score<3) ? printf("\033[0;33m\033[4m %5.2f\n", album->score) : (album->score<8)? printf("\033[0;32m\033[4m %5.2f\n", album->score) : printf("\033[0;31m\033[4m %5.2f\n", album->score);
		printf("\033[0;37m\033[4m");
		album = album->next;
	}
	printf("%36s | %25s | %4d | %20s |", album->name, album->interpreter, album->year, album->genre);
	(album->score<3) ? printf("\033[0;33m\033[4m %5.2f\n\n", album->score) : (album->score<8)? printf("\033[0;32m\033[4m %5.2f\n", album->score) : printf("\033[0;31m\033[4m %5.2f\n", album->score);
	printf("\033[0;37m");
    printf("\033[0m");
}


album_t *getAlbum(album_t *album_list, char *name)
{
	int album_count = getAlbumCount(album_list);
	for (int a = 0; a < album_count; a++)
	{
		if(strcmp(album_list->name, name) == 0) return album_list;
		album_list = album_list->next;
	}
	return NULL;
}