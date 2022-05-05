#include "language.h"

// private ----------------------------------------------------------------
// aritmetics -------------------------------------------------------------

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
    return (isOperator(x)||isNumber(x)||(x==')')||(x=='(')) ? true : false;
}

bool isLatter(char x)
{
    return (((x>64)&&(x<91))||((x>96)&&(x<123))) ? true : false;
}

bool isSymbolValid(char x)
{
    //          numbr           big latter      small latter
    return (isNumber(x)||isOperator(x)||isMathSim(x)||isLatter(x)||(x==' ')||(x=='_')||(x=='-')||(x==',')) ? true : false;
}

void sintaxError(char *x)
{
    printf("\033[0;31m");
    printf("bad syntax in %s\n", x);
    printf("\033[0;37loadm");
}

readed_number_t loadBracket(char *bracket)
{
    char *x = (char *)malloc(sizeof(char)*BUFFERSIZE);
    int a = 1;
    int n = 0;
    while(!((bracket[a]==')')&&(n<1)))
    {
        if(bracket[a]=='(') n++;
        else if(bracket[a]==')') n--;
        x[a-1]=bracket[a];
        a++;
    }
    x[a-1]=';';
    x[a]=';';
    readed_number_t out = interpretArithmeticsFunction(x);
    out.length +=2;
    return out;
}

readed_number_t loadAnother(char *another)
{
    readed_number_t out;
    out.length = 0;
    out.value = 0;
    if(isNumber(another[0])||(another[0]=='+')||(another[0]=='-')) return loadNumber(another);
    if(another[0]=='(') return loadBracket(another);
    if(another[0]==';') return out;
    sintaxError(another);
    return out;
}

readed_number_t combineNumber(readed_number_t a, readed_number_t b, char marker)
{
    readed_number_t c;
    switch(marker)
    {
    case '+':
        c.value = a.value + b.value;
        c.length = a.length + b.length + 1;
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
        x = loadAnother(example);
        if((example[x.length]=='*')||(example[x.length]=='/')) x = combineNumber(x, loadAnother(&example[x.length+1]),example[x.length]);
    }
    readed_number_t out = combineNumber(x,interpretArithmeticsFunction(&example[x.length+1]), example[x.length]);
    return out;
}

// database ---------------------------------------------------------------

bool compareText(char *A, char *B, int A_length)
{
    if(B[A_length]!='\0') return false;
    for (int a = 0; a < A_length; a++)
    {
        if(A[a] != B[a]) return false;
    }
    return true;
}

void doDatabaseFunction(char *command, int command_length)
{
    if(compareText(command, "load-file"      , command_length)) return loadFile_i               (&command[command_length+1]);
    if(compareText(command, "del-album"      , command_length)) return delAlbum_i               (&command[command_length+1]);
    if(compareText(command, "save-album-list", command_length)) return saveAlbumsList_i         (&command[command_length+1]);
    if(compareText(command, "list"           , command_length)) return printfAllAlbums_i        (&command[command_length+1]);
    if(compareText(command, "add-album"      , command_length)) return addNewAlbum_i            (&command[command_length+1]);
    if(compareText(command, "sort-albums"    , command_length)) return sortAlbums_i             (&command[command_length+1]);
    if(compareText(command, "album-count"    , command_length)) return getAlbumCount_i          (&command[command_length+1]);
    if(compareText(command, "album"          , command_length)) return getAlbum_i               (&command[command_length+1]);
    if(compareText(command, "filter-album"   , command_length)) return getAlbumSortedList_i     (&command[command_length+1]);
    if(compareText(command, "save-filter"    , command_length)) return saveFilteredAlbumList_i  (&command[command_length+1]);
    if(compareText(command, "change-album"   , command_length)) return changeAlbumRecord        (&command[command_length+1]);
    if(compareText(command, "print-filter"   , command_length)) return printFilteredAlbumList_i (&command[command_length+1]);

    printf("\033[0;31m");
    printf("unknown function\n");
    printf("\033[0;37m");
}


// public  ----------------------------------------------------------------
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

int readLine(char *buffer)
{
    printf("\033[0;32m\033[1m\033[5m--> \033[0m\033[0;35m");

    int a = 0;
    for (a = 0; (a < BUFFERSIZE)&&(buffer[a-1]!=10); a++)
    {
        scanf("%c", &buffer[a]);
    }
    buffer[a] = '\0';
    for (a = 0; (a < BUFFERSIZE)&&(buffer[a]!=10); a++)
    {
        if(!isSymbolValid(buffer[a])) 
        {
            printf("\nthere is some non valid symbol\n");
            buffer[0] = ';';
        }
    }
    printf("\033[0;37m");
    buffer[a] = ';';
    buffer[a+1] = ';';
    for (a = 0; buffer[a]==' '; a++) {}
    return a;
}

bool interpretLine(char *line)
{
    if(isMathSim(line[0])) 
    {
        readed_number_t math = interpretArithmeticsFunction(line);
        printf("\n%4.2f\n",math.value);
        return math.length-1;
    }
    else if(isLatter(line[0])) 
    {
        interpretDatabaseFunction(line);
    }
    return true;
}

void interpretDatabaseFunction(char *command)
{
    int command_length;
    for (command_length = 0; !((command[command_length] == ' ')||(command[command_length] == ';')); command_length++){}
    doDatabaseFunction(command, command_length);
}