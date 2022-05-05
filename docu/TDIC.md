<embed src="TDIC.pdf" type="application/pdf">

TDIC (Terminál Database Interpretre Calculator)
===============================================

TDIC je terminálový program schopný primitivní práce s databází alb a také je schopen počítat matematické výrazy. Databáze je realizovaná lineárním seznamem, v němž každý prvek ukazuje na předchozí a nanásledující prvek. Z terminálového okna je uživatel schopen načíst databázi ze souboru .csv se správnou strukturou. Dále je možné setřídit seznam dle libovolného parametru, vyfiltrovat podle jednoho nebo více parametrů, spočítat množství záznamů, přidat, odebrat nebo změnit záznam a \"databázi\" opět uložit do souboru .csv. Výsledek filtru je také možno uložit do samostatného souboru .csv.

TDIC se skládá z několika souborů, které mají na starost řešení logických celků. Jednotlivé soubory obsahují dva typy funkcí, \"private\" a \"public\". Private funkce jsou přístupné jen z daného souboru, když jsem odkázán na čisté C a nemám private metody, tak je to hold takhle.

Obsluha programu
================

Početní část
------------

Při používání početní části programu lze libovolný numerický příklad zadat v přirozené podobě např. $2/4-5*(4+2/(2+3))$ program vyhodnotí jako $-21.50$. Implementované operátory jsou \"+\", \"-\", \"\*\", \"/\" a \"%\" jakož to modulo. Krom zmíněných znamének může příklad obsahovat čísla a libovolné množství závorek. Výsledek se zobrazí jako prosté číslo v desetinném tvaru s přesností na dvě desetinná místa. Pokud při zadávání dojde k chybě v zadání (např. neuzavřete závorku nebo se v příkladu vyskytne nematematický symbol) program vypíše \"bad syntax in \" a část příkladu, ve která našel chybu. Příklad přesto vyhodnotí a výsledek vypíše hned pod chybovou hlášku, pokud jste tedy jen zapomněli uzavřít závorku, nemusíte příklad psát celý znova.

databázová část
---------------

Pokud zadáte funkci, která není definovaná, vypíše se \"unknown function\". Konkrétně jsou funkce popsány v následující kapitole. 
Pokud funkce přebírá parametry budou vždy odděleni mezerou. \"\_i\" v názvu funkce značí, že jde o verzi funkce, která je určena pro parser a existuje i stejná funkce bez \"\_i\" která je součástí \"\_i\" a slouží pro použití uvnitř programu.

|název funkce v konzoly                             | název funkce uvnitř programu|
|---------------------------------------------------|-----------------------------|
|load-file $<$file\_path$>$                         | loadFile\_i                 |  
|del-album                                          | delAlbum\_i                 |
|save-album-list $<$file\_path$>$                   | saveAlbumsList\_i           |  
|list                                               | printfAllAlbums\_i          |  
|add-album $<$album data$>$                         | addNewAlbum\_i              |
|sort-albums $<$compare\_faktor$>$ $<$sort\_dir$>$  | sortAlbums\_i               |   
|album-count                                        | getAlbumCount\_i            |  
|album $<$name$>$                                   | getAlbum\_i                 |
|filter-album $<$filter seting$>$                   | getAlbumSortedList\_i       |
|save-filter $<$file\_path$>$                       | saveFilteredAlbumList\_i    |  
|change-album $<$name$>$ $<$changing param$>$       | changeAlbumRecord           |      
|print-filter                                       | printFilteredAlbumList\_i   |

```
#include "includ/album_driver_interpret.md"
```
#include "includ/language.md              "
```
#include "includ/album_driver.md          "
```
#include "includ/album_filter.md          "
```
#include "includ/csv_manager.md           "
```