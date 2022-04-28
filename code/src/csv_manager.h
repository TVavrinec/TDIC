#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct cell_t
{
    char text[32];
    double number;
    int type;
    int index;
}cell_t;

enum cell_type 
{
    anything = 0,
    number,
    text,
};

enum call_end
{
    normal = 0,
    endLine,
    endFile,
    new,
};

//private

//bool itsANmber(char sim);
//bool itsAText(char sim);
//bool itsASpecialSymbol(char sim);

//public

FILE *openFile(char *file_path, char *mode);

cell_t readFileCell(FILE *file);