#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "csv_manager.h"
#include "album_driver.h"
#include "album_filter.h"

#include "language.h"

int main( void)
{
	album_t *album_list = loadFile("/home/mtar/Documents/skola/s2/PC2M/C10/output/zadani10_databaze.csv");
	printfAllAlbums(album_list);
	while (true)
	{
		char *buffer = (char*)malloc(sizeof(char)*BUFFERSIZE);
		int x = readLine(buffer);
		interpretLine(&buffer[x]);
		free(buffer);
	}
  	return 0;
}