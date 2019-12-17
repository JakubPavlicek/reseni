/*
  Write a "task03" program for basic adding. It should handle -f, -i and -v parameters
  task03 -f data.txt // outputs sum of numbers in data.txt
  task03 -i // interactive mode: sums numbers from standard input until empty input provided
  task03 4 7 12 // outputs sum of any number of arguments (23 in this case)
  implement verbose mode -v, which outputs additional info about arguments, i.e.
    task03 -f data.txt -v // should print "sum of numbers in data.txt is 13"
    task03 -v -f data.txt // same result
    task03 -v -i // should print like "sum of 7 numbers from standard input is 38"
    task03 2 2 13 6 -v // should print "sum of 4 arguments is 23"
    task03 -v 13 4 // should print "sum of 2 arguments is 17"
*/

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

int main(int argc, char* argv[]) {

  char fileCont[255];   // proměnná char mi definuje charaktery, složená závorka mi nastavuje velikost charakterů na 255
  int i;                
  int vysledek = 0;     // proměnná int mi definuje celá čísla  
  int cisla[80];
  bool verbose = 0;     // proměnná bool mi definuje buď 0 nebo 1
                        

  if(strcmp(argv[1], "-f") == 0) {    // pokud se argv[1] a "-f" rovnají funkce vrací 0
    FILE *fp = fopen(argv[2], "r");   // otevře soubor jenom pro čtení

    if(strcmp(argv[3], "-v") == 0) {
      verbose = 1;
    }
    else {
      verbose;
    }

    while(fscanf(fp, "%s", fileCont) != EOF) // funkce fscanf čte ze souboru, v tomto případě čte text
    {
      sscanf(fileCont,"%d",&i); // funkce sscanf v tomto případě načítá čísla ze souboru
      vysledek += i;
    }
    if(verbose == 0)  
      printf("%d", vysledek);
    else{
      printf("sum of numbers in %s is %d", argv[2], vysledek);
    }
  }


  if(strcmp(argv[1], "-i") == 0) {
    int pocetCisel = 0;
    if(strcmp(argv[2], "-v") == 0) {
      verbose = 1;
    }
    else{
      verbose;
    }

    for(int x = 0; x < 80; x++){
      scanf("%d", &cisla[x]); // funkce scanf udělá to, že uživatel mi dosadí číslo do x
      if(getchar() != 'e') {  // funkce getchar() mi způsobí přerušení smyčky pomocí charakteru 'e'
        vysledek += cisla[x]; // operátor += sčítá
        pocetCisel++; // pocetCisel++ bude pokaždý co se provede tato podmínka přičítat 1
        continue;
      }
      else{
        break;
      }
    }
    if(verbose == 0){
      printf("%d", vysledek);
    }
    else{
      printf("sum of %d numbers from standard input is %d", pocetCisel, vysledek);  // printf v tomto případě vypíše pocetCisel a vysledek, přičemž výsledek
    }                                                                               // součet zadaných čísel uživatelem
  }

  return 0;
}
