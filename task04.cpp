#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

struct Animal {
  char name[50];
  char whatDoesItSay[50];
};

int main() {
  
  struct Animal Dog;
  strcpy(Dog.name, "dog");
  strcpy(Dog.whatDoesItSay, "woof");

  struct Animal Fox;
  strcpy(Fox.name, "fox");
  strcpy(Fox.whatDoesItSay, "ringidingidingidingiding");

  printf("Animal %s says %s\n", Dog.name, Dog.whatDoesItSay);
  printf("Animal %s says %s\n", Fox.name, Fox.whatDoesItSay);
  // dog says woof
  // fox says ringidingidingidingiding
}