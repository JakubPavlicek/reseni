/*
  Write a "task03" program for basic adding. It should handle -f, -i and -v parameters
  --task03 -f data.txt // outputs sum of numbers in data.txt
  --task03 -i // interactive mode: sums numbers from standard input until empty input provided
  --task03 4 7 12 // outputs sum of any number of arguments (23 in this case)
  implement verbose mode -v, which outputs additional info about arguments, i.e.
    --task03 -f data.txt -v // should print "sum of numbers in data.txt is 13"
    --task03 -v -f data.txt // same result
    --task03 -v -i // should print like "sum of 7 numbers from standard input is 38"
    --task03 2 2 13 6 -v // should print "sum of 4 arguments is 23"
    --task03 -v 13 4 // should print "sum of 2 arguments is 17"
*/

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

int arg(int argc, char* argv[]){
    int sum = 0;
    int num;
        for(int z = 1; z < argc; z++){
          if(strcmp(argv[z], "-v") != 0){
            sscanf(argv[z], "%d", &num);
            sum += num;
          }
        }
        printf("sum of %d arguments is %d", argc - 2, sum);
        exit(1);
}

int main(int argc, char* argv[]){

char fileCont[255];  
int x;                
int vysledek = 0;      
int cisla[80];

if(argv[0][0] != '-' && strcmp(argv[1], "-i") != 0 && strcmp(argv[1], "-f") !=0 && strcmp(argv[1], "-i") !=0){
    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "-v") == 0 && strcmp(argv[2], "-f") !=0 && strcmp(argv[2], "-i") !=0){
            arg(argc, argv);
        }
    }
}

while((++argv)[0]){
    
    if(argv[0][0] != '-'){

        int sum = 0;
        for(int n = 0; n < argc; n++){
          sum += atoi(argv[n]);
        }
        printf("%d", sum);
        return 0;
    }
    
    

    if(argv[0][0] == '-' ){

        switch(argv[0][1]){
            
            case 'f' :
            {
                FILE *fp = fopen(argv[1], "r");
                while(fscanf(fp, "%s", fileCont) != EOF){
                    sscanf(fileCont, "%d", &x); 
                    vysledek += x;
                }
            
                if(!argv[2]){
                    printf("%d", vysledek);
                    return 0;
                }

                if(argv[2][0] == '-' && argv[2][1] == 'v'){    
                    printf("sum of numbers in %s is %d", argv[1], vysledek);
                    return 0;
                }
            }

            case 'i' :
            {
                int pocetCisel = 0;
                for(int y = 0; y < 10; y++){
                    scanf("%d", &cisla[y]); 
                    if(getchar() != 'e'){
                        vysledek += cisla[y];
                        pocetCisel++;
                        continue;
                    }else{
                        break;
                    }
                }
            printf("%d", vysledek);
            return 0;
            }
    }

    if(argv[0][1] == 'v'){
        if(argv[1][0] == '-'){
            switch(argv[1][1]){
                case 'f' :
                {
                    int vysledek = 0;
                    FILE *fp = fopen(argv[2], "r");
                    while(fscanf(fp, "%s", fileCont) != EOF){
                        sscanf(fileCont, "%d", &x); 
                        vysledek += x;
                    }
                printf("sum of numbers in %s is %d", argv[2], vysledek);
                return 0;
                }
                
                case 'i' :
                {
                    int pocetCisel = 0;
                for(int y = 0; y < 10; y++){
                    scanf("%d", &cisla[y]); 
                    if(getchar() != 'e'){
                        vysledek += cisla[y];
                        pocetCisel++;
                        continue;
                    }
                    else{
                        break;
                    }
                }
                printf("sum of %d numbers from standard input is %d", pocetCisel, vysledek);
                return 0;
            }
        }
    }
}
}
}
}
