#include "language.h"

// private ----------------------------------------------------------------

bool isSymbolValid(char x)
{
    //          numbr           big latter      small latter
    return (((x>47)&&(x<58))||((x>65)&&(x<91))||((x>96)&&(x<123))||(x=='+')||(x=='-')||(x=='*')||(x=='/')||(x=='%')||(x=='(')||(x==')')||(x==' ')||(x=='.')) ? true : false;
}

bool isNumber(char x)
{
    return (((x>47)&&(x<58))||(x=='.')) ? true : false;
}

bool isOperator(char x)
{
    return ((x=='+')||(x=='-')||(x=='*')||(x=='/')||(x=='%')) ? true : false;
}

bool isMathSim(char x)
{
    return ((x=='+')||(x=='-')||(x=='*')||(x=='/')||(x=='%')||((x>47)&&(x<58))||(x==')')||(x=='(')||(x=='.')) ? true : false;
}

bool isLatter(char x)
{
    return ((x>65)&&(x<91)) ? true : false;
}

interpret_function_t *newFunction()
{
    interpret_function_t *function = (interpret_function_t *)malloc(sizeof(interpret_function_t));
    function->argument = NULL;
    function->function = -1;
    function->function_type = -1;
    return function;
}

void sintaxError(char *x)
{
    printf("bed sintax in %s\n", x);
}

readed_number_t loadNumber(char *number)
{
    readed_number_t out = {0,0};
    char *x = (char *)malloc(sizeof(char)*24);
    int a = 0;
    if((number[a]=='-')||(number[a]=='+')) {x[a] = number[a]; a++;}
    if(number[a]==';') {return out;}
    for (; isNumber(number[a]); a++)
    {
        if((a>24)||!isMathSim(number[a]))
        {
            x[25] = '\0';
            sintaxError(x);
            return out;
        }
        x[a] = number[a];
    }
    x[a] = '\0';
    out.length = a;
    out.value = atof(x);
    free(x);
    return out;
}

readed_number_t combineNumber(readed_number_t a, readed_number_t b, char marker)
{
    readed_number_t c;
    switch(marker)
    {
    case '+':
        c.value = a.value + b.value;
        c.length = a.length + b.length;
    break;
    case '-':
        c.value = a.value - b.value;
        c.length = a.length + b.length + 1;
    break;
    case '*':
        c.value = a.value * b.value;
        c.length = a.length + b.length + 1;
    break;
    case '/':
        c.value = a.value / b.value;
        c.length = a.length + b.length + 1;
    break;
    case '%':
        c.value = ((int)a.value)%((int)b.value);
        c.length = a.length + b.length + 1;
    break;
    case ')':
        c.value = a.value;
        c.length = a.length;
    break;
    case ';':
        c.value = a.value;
        c.length = a.length;
    break;
    default:
        sintaxError(NULL);
        break;
    }
    return c;
}

readed_number_t interpretArithmeticsFunction(char *example)
{
    readed_number_t x;
    x.value = 0;
    x.length = 0;
    if((example[0] == ';')||(example[0] == ')')) return x;
    if(example[0] == '(')
    {
        x = interpretArithmeticsFunction(&example[1]);
        x.length++;
        if(example[x.length] != ')') {sintaxError(example); return x;}
        x.length++;
    }
    else
    {
        x = loadNumber(example);
    }
    readed_number_t out = combineNumber(x,interpretArithmeticsFunction(&example[x.length+1]), example[x.length]);
    return out;
}

// public  ----------------------------------------------------------------

void readLine(char *buffer)
{
    int a = 0;
    for (a = 0; (a < BUFFERSIZE)&&(buffer[a-1]!=10); a++)
    {
        scanf("%c", &buffer[a]);
    }
    for (a = 0; (a < BUFFERSIZE)&&(buffer[a]!=10); a++)
    {
        if(!isSymbolValid(buffer[a])) 
        {
            printf("\nthere is some non valid symbol\n");
            buffer[0] = ';';
        }
    }
    buffer[a] = ';';
    buffer[a+1] = ';';
}

bool interpretLine(char *line)
{
    for(int a = 0; (line[a] != ';')&&(a<BUFFERSIZE); a++)
    {
        if(line[a] == ' ') continue;
        a += interpretWord(&(line[a]));
    }
    return true;
}

int interpretWord(char *word)
{
    int a = 0;
    interpret_function_t *function = newFunction();
    char *x = (char *)malloc(sizeof(char)*32);
    if(isMathSim(word[a])) 
    {
        function->function_type = aritmetics;
        readed_number_t math = interpretArithmeticsFunction(word);
        printf("\n%4.2f\n",math.value);
        free(x);
        free(function);
        return math.length-1;
    }
    else if(isLatter(word[a])) 
    {
        function->function_type = clasics_function; 
    }
    free(x);
    free(function);
    return a-1;
}