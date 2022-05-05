Parser
======

Private funkce aritmetické části parseru
----------------------------------------

``` {style="CStyle"}
bool isNumber(char x);     
bool isOperator(char x);   
bool isMathSim(char x);    
bool isLatter(char x);     
bool isSymbolValid(char x);
```

Tyto funkce slouží pro pohodlnější definici podmínek a jediné co dělají
je, že ověřují, zda je daný znak číslo, operátor atd.

``` {style="CStyle"}
readed_number_t loadAnother(char *another);
readed_number_t loadNumber(char *number);  
readed_number_t loadBracket(char *bracket);
```

Tyto funkce slouží matematickému parseru pro přečtení části řetězce s
matematickým výrazem. Funkce $"loadAnother"$ slouží jako rozcestí, které
rozhoduje, zda se má zavolat $loadNumber$ nebo $laadBracket$. Všechny
tři následně vracejí strukturu, která obsahuje hodnotu dané části
výpočtu a její délku, kterou zabírala ve vstupním řetězci.\

``` {style="CStyle"}
readed_number_t combineNumber(readed_number_t a, readed_number_t b, char marker);
```

Tato funkce slouží pro samotné kombinování (sčítání, odčítání atd.)
čísel ze struktur \"a\" a \"b\" podle znaménka v parametru \"marker\".\

Private funkce databázového části parseru
-----------------------------------------

``` {style="CStyle"}
void doDatabaseFunction(char *command, int command_length);
```

Tato funkce je rozcestí pro konkrétní databázové funkce, které jsou vždy
popsané při své deklaraci.

Funkce pro použití mimo knihovnu
--------------------------------

``` {style="CStyle"}
/*
    load number from text and return his value and his length in text format
*/
readed_number_t loadNumber(char *number);
```

Načte číslo z textu v paměti na adrese \"number\" a vrátí ho ve
struktuře \"readed\_number\_t\". Tato struktura obsahuje číselnou
hodnotu čteného čísla a počet znaků, který v textu zaujímalo.

``` {style="CStyle"}
/*
    load line from the terminal and add ";;" to the end of the string
*/
int readLine(char *buffer);
```

Načte do paměti na adresu \"buffer\" textu, který uživatel zadal do
konzole a ukončí jej dvěma středníky \";;\" podle kterých se pak
orientuje následující část programu.

``` {style="CStyle"}
/*
    interpret text ended ";;"
    you can calculate math expressions and do database functions
*/
bool interpretLine(char *line);
```

Spočítá matematické příklady a vykoná databázové příkazy uložené v
textovém řetězci v paměti na adrese \"line\". Předpokládá zakončení
řetězce dvěma středníky \";;\".

``` {style="CStyle"}
/*
    calculate expressions from text ended ";;"
*/
readed_number_t interpretArithmeticsFunction(char *example);
```

Vypočte matematický příklad uložený v textovém řetězci v paměti na
adrese \"example\". Předpokládá zakončení řetězce dvěma středníky
\";;\".

``` {style="CStyle"}
/*
    do databas function describ in text "command" and end ";;"
    function is describ in file "album_driver_interpret.h"
*/
void interpretDatabaseFunction(char *command);
```

vykoná databázové příkazy uložené v textovém řetězci v paměti na adrese
\"command\". Předpokládá zakončení řetězce dvěma středníky \";;\".
