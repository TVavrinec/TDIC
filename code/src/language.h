#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define BUFFERSIZE 1024

enum function_type 
{
    aritmetics = 0,
    clasics_function,
};

typedef struct function_argument_t function_argument_t;

typedef struct function_argument_t
{
    char *argument;
    function_argument_t *next;
}function_argument_t;

typedef struct interpret_function_t
{
    int function;
    int function_type;
    function_argument_t *argument;
} interpret_function_t;

typedef struct readed_number_t
{
    double value;
    int length;
}readed_number_t;

// private ----------------------------------------------------------------
// bool isSymbolValid(char x);
// bool isNumber(char x);
// bool isLatter(char x);
// bool isOperator(char x);

// interpret_function_t *newFunction();
// public  ----------------------------------------------------------------
void readLine(char *buffer);

bool interpretLine(char *line);
int interpretWord(char *word);