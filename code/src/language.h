#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "album_driver_interpret.h"

#define BUFFERSIZE 1024

typedef struct function_argument_t function_argument_t;

typedef struct readed_number_t
{
    double value;
    int length;
}readed_number_t;

/* private ----------------------------------------------------------------
aritmetics ----------------------------------------------------------------

bool isNumber(char x);
bool isOperator(char x);
bool isMathSim(char x);
bool isLatter(char x);
bool isSymbolValid(char x);

interpret_function_t *newFunction();
readed_number_t loadAnother(char *another);
readed_number_t loadNumber(char *number);
readed_number_t loadBracket(char *bracket);

readed_number_t combineNumber(readed_number_t a, readed_number_t b, char marker);

database ------------------------------------------------------------------

void doDatabaseFunction(char *command, int command_length);
// public  ----------------------------------------------------------------*/

/*
    load number from text and return his value and his length in text format
*/
readed_number_t loadNumber(char *number);

/*
    load line from the terminal and add ";;" to the end of the string
*/
int readLine(char *buffer);

/*
    interpret text ended ";;"
    you can calculate math expressions and do database functions
*/
bool interpretLine(char *line);

/*
    calculate expressions from text ended ";;"
*/
readed_number_t interpretArithmeticsFunction(char *example);

/*
    do databas function describ in text "command" and end ";;"
    function is describ in file "album_driver_interpret.h"
*/
void interpretDatabaseFunction(char *command);