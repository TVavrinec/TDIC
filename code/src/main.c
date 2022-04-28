#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "csv_manager.h"
#include "album_driver.h"
#include "album_filter.h"

#include "language.h"

#include "mat.h"


int main( void)
{
	char *buffer = (char*)malloc(sizeof(char)*BUFFERSIZE);
	readLine(buffer);
	interpretLine(buffer);
	free(buffer);
  	return 0;
}