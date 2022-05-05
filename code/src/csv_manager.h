#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef enum  
{
    anything = 0,
    number,      
    text,        
}cell_type;

typedef enum
{
    normal = 0,
    endLine,
    endFile,
}call_end;

typedef struct cell_t
{
    char text[32];
    double number;
    cell_type type;
    call_end index;
}cell_t;


//private

//bool itsANmber(char sim);
//bool itsAText(char sim);
//bool itsASpecialSymbol(char sim);

//public

/*
    open file on address "file_pad"
    if the file does not exist or is not readable print "Error!!! the file \"%s\" does not exist or is not readable" and return NULL 
*/
FILE *openFile(char *file_path, char *mode);

/*
    read text in file to ';' and if the text in number translates it
    return struct call_t with read text, number value and actual state in reading file:
        end of call = normal  = 0
        end of line = endLine = 1
        end of file = endFile = 2
    in struct is info about call type:
        anything = 0 //
        number   = 1 // is translated to number
        text     = 2 // is contane only 'a'->'z' 'A'->'Z' '0'->'9' '.' ',' space '_' '-'
*/
cell_t readFileCell(FILE *file);