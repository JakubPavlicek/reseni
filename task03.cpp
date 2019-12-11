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

  char fileCont[255];
  int i;
  int vysledek = 0;
  int cisla[80];
  bool verbose = 0;

  if(strcmp(argv[1], "-f") == 0) {
    FILE *fp = fopen(argv[2], "r");

    if(strcmp(argv[3], "-v") == 0) {
      verbose = 1;
    }
    else {verbose;}

    while(fscanf(fp, "%s", fileCont) != EOF)
    {
      sscanf(fileCont,"%d",&i);
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
    else{verbose;}

    for(int j = 0; j < 80; j++){
      scanf("%d", &cisla[j]);
      if((getchar()) != 'e') {
        vysledek += cisla[j];
        pocetCisel++;
        continue;
      }
      else{
        break;
      }
    }
    if(verbose == 0)
      printf("%d", vysledek);
    else{
      printf("sum of %d numbers from standard input is %d", pocetCisel, vysledek);
    }
  }

  return 0;
}
