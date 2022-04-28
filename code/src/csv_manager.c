#include "csv_manager.h"

//private

bool itsANmber(char sim)
{
    return (((sim > 47)&&(sim < 58))||(sim == '.')||(sim == ',')||(sim == ' ')) ? true : false;
}

bool itsAText(char sim)
{
    return (((sim >= 'a')&&(sim <= 'z'))||((sim >= 'A')&&(sim <= 'Z'))||
            ((sim >= '0')&&(sim <= '9'))||
            (sim == '.')||(sim == ',')||(sim == ' ')||(sim == '_')||(sim == '-'))
            ? true : false;
}

bool itsASpecialSymbol(char sim)
{
    return ((sim == ';')||(sim == 13)||(sim == EOF)) ? true : false;
}

//public
                                 
cell_t readFileCell(FILE *file)
{
    cell_t call;
    for (int a = 0; a < 32; a++)    call.text[a] = '\0';
    bool type[2] = {true,true};
	char sim = fgetc(file);
	for(int a = 0; !itsASpecialSymbol(sim); a++)
	{
		call.text[a] = sim;
        if(!itsANmber(sim))  type[0] = false;
        if(!itsAText(sim))  type[1] = false;
        sim = fgetc(file);
    }
    call.type = (type[0]) ? number : ((type[1]) ? text : anything);  
    call.number = (call.type == number) ? atof(call.text) : 0;
    switch (sim)
    {
        case ';'  :call.index = normal ; break;
        case 13 :call.index = endLine; fgetc(file); break;
        case EOF  :call.index = endFile; break;
        default: break;
    }
	return call;
}

FILE *openFile(char *file_path, char *mode)
{
	FILE *file = fopen(file_path, mode);
    if (file == NULL)
    {
        printf("AAAAAAAAAAaaaaaaaa konec sveta neotevrel se mi soubor %s  aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", file_path);
        return 0;
    }
    return file;
}