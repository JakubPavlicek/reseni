#include <iostream>

using namespace std;

/*
  Napište abstraktní třídu Button s ryze virtuálními metodami waitForButton 
  (která bude čekat na stisk tlačítka) 
  a hello 
  (která vytiskne hello při každém stisku tlačítka).
  Napište její hardwarovou implementaci pro PC jménem ButtonPC 
  (waitForButton bude čekat na stisk enter a hello bude vypisovat na konzoli).
  Dobře navržený kód umožní použití třídy Button na Arduinu 
  (waitForButton bude čekat na stisk připojeného tlačítka a hello bude vypisovat na Sériovou linku). 
  Tuto část si demonstrujeme spolu při hodině.
*/

struct Button{
    virtual void waitForButton() = 0;
    virtual void hello() = 0;
    void loop();
};

struct ButtonPC : Button{

    void waitForButton(){  
        loop();
    };

    void loop(){
        char c = getchar();
        while (true){
            hello();
            waitForButton();
        };
    };

    void hello(){
            printf("hello\n");
    }
};

int main(){

    ButtonPC b;
    b.waitForButton();

}
