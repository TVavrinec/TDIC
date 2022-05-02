#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "album_driver_interpret.h"

#define BUFFERSIZE 1024

enum function_type 
{
    aritmetics = 0,
    clasics_function,
};

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
readed_number_t laadBracket(char *bracket);

readed_number_t combineNumber(readed_number_t a, readed_number_t b, char marker);

database ------------------------------------------------------------------

void doDatabaseFunction(char *command, int command_length);
// public  ----------------------------------------------------------------*/
readed_number_t loadNumber(char *number);

int readLine(char *buffer);

bool interpretLine(char *line);

readed_number_t interpretArithmeticsFunction(char *example);

void interpretDatabaseFunction(char *command);