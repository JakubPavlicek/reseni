#include <iostream>
#include <string.h>

using namespace std;

struct Animal {

  const char* name;
  const char* say;
  char arr[255];
  virtual void whatDoesItSay() = 0;

    Animal(const char* name, const char* say){
    this->name = name;
    this->say = say;
  }
};

struct Dog : Animal {

  Dog(const char* name, const char* say) : Animal(name, say){}

    
    void whatDoesItSay() {
    strcpy(arr, name);
    strcat(arr, " rika ");
    strcat(arr, say);
    puts(arr);
  }
};

struct Fox : Animal {
   
  Fox(const char* name, const char* say) : Animal(name, say){}

    void whatDoesItSay() {
    strcpy(arr, name);
    strcat(arr, " rika ");
    strcat(arr, say);
    puts(arr);
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
