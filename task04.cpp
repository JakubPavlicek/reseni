#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

struct Animal {

  const char* name;
  const char* say;
  virtual void whatDoesItSay() = 0;

    Animal(const char* name, const char* say){
    this->name = name;
    this->say = say;
  }
};

struct Dog : Animal {

  Dog(const char* name, const char* say) : Animal(name, say){}

  void whatDoesItSay() {
    cout << this->name << " rika " << this->say << endl;
  }
};

struct Fox : Animal {
   
  Fox(const char* name, const char* say) : Animal(name, say){}

  void whatDoesItSay() {
    cout << this->name << " rika " << this->say << endl;
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
