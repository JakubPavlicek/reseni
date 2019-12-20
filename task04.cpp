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

// DALŠÍ POKUS O FUNKČNOST, AVŠAK TENTO KÓD DOLE MI PÍŠE ERROR undefined reference to `vtable for Animal' A NEVÍM PROČ

/*
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

struct Animal {

  char buffer[48];
  const char* name;
  const char* say;
  virtual const char* whatDoesItSay();
  // TODO
    Animal(const char* name, const char* say){
    this->name = name;
    this->say = say;
  }
};

struct Dog : Animal {
  // TODO
  
  Dog(const char* name, const char* say) : Animal(name, say){};

  const char* whatDoesItSay(){
    sprintf(buffer, "Zvire %s rika %s", name, say);
    return buffer;
  }
};

struct Fox : Animal {
  // TODO
   
  Fox(const char* name, const char* say) : Animal(name, say){};

  const char* whatDoesItSay(){
    sprintf(buffer, "Zvire %s rika %s", name, say);
    return buffer;
  }
};

int main() {

Animal* animals[] = {
    new Dog("dog", "woof"),
    new Fox("fox", "ringidingidingidingiding")
  };
  for(Animal* animal : animals) {
    animal->whatDoesItSay();
  }
}
  // dog says woof
  // fox says ringidingidingidingiding
*/
