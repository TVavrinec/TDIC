Asistent pro načítání souboru
=============================

Pro jednoduchost budu dále používat zkratku ANS (Asistent pro Načítání
Souboru).

Private funkce ANS
------------------

``` {style="CStyle"}
bool itsANmber(char sim);
    bool itsAText(char sim);
    bool itsASpecialSymbol(char sim);
```

Tyto funkce slouží pro pohodlnější definici podmínek a jediné co dělají
je, že ověřují, zda je daný znak číslo, text nebo speciální znak.

Funkce pro použití mimo knihovnu ANS
------------------------------------

``` {style="CStyle"}
/*
    open file on address "file_pad"
    if the file does not exist or is not readable print "Error!!! the file \"%s\" 
    does not exist or is not readable" and return NULL 
*/
FILE *openFile(char *file_path, char *mode);
```

Otevře soubor a vrátí ukazatel, pokud soubor neexistuje nebo není z
nějakého důvodu čitelný, vypíše do terminálu \"Error!!! the file
$\backslash$\"%s$\backslash$\" does not exist or is not readable\" a
vrátí NULL. Na místo %s pochopitelně vypíše cestu k souboru který
neotevřel.

``` {style="CStyle"}
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
```

Přečte buňku ze souboru a vrátí ji ve struktuře \"cell\_t\". Struktura
\"cell\_t\" slouží pro snadnou orientaci v načtených datech. Struktura
obsahuje načtený text \"char text\[32\]\", pokud se jedná o číslo tak
obsahuje jeho číselnou hodnotu \"double number\"(pokud nejde o číslo
číselná složka bude = 0), informaci o typu dat \"cell\_type type\" a
nakonec informaci o průběhu čtení souboru \"call\_end index\".\
Pro složku \"cell\_type type\" můžete využít enum \"cell\_type\".

``` {style="CStyle"}
typedef enum  
{
    anything = 0,
    number,      
    text,        
}cell_type;
```

Pro složku \"call\_end index\" můžete využít enum \"call\_end\".

``` {style="CStyle"}
typedef enum
{
    normal = 0,
    endLine,
    endFile,
}call_end;
```
