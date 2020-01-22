#include <iostream>
#include <bits/stdc++.h> 
#include <ncurses.h>

using namespace std;

class Game{
    public:
    virtual bool checkWin()=0;
    virtual void makeMove()=0;
    virtual void printResult()=0;

    int x, y;

    bool turn = true;

    void startGame(){
        while(checkWin() == false){
            //turn = !turn;
            makeMove();
        }
        printResult();
    }
};

class Player1 : public Game{
    public:
     
    void makeMove(){
        for(!turn;;){
            cout << "Player1 tipnul: ";
            x = getchar();
            if(getchar()=='\n' && x >= 97 && x <= 122){
                return;
            }else{
                continue;
            }
            !turn;
        }
    };

    void printResult(){
        cout << "Player1 won!";
    }; 

    bool checkWin(){  
        if(x>y){
            printResult();
        }else{
            return false;
        }
    };
};

class Player2 : public Game{
    public:

    void makeMove(){
        for(turn;;){
            cout << "Player2 tipnul: ";
            y = getchar();
            if(getchar()=='\n' && y >= 97 && y <= 122){
                return;
            }else{
                continue;
            }
            !turn;
        }
    };

    void printResult(){
        cout << "Player2 won!";
    };

    bool checkWin(){
        if(y>x){
            printResult();
        }else{
            return false;
        }
    };
};

int main(){

    
    Player1 p1;
    Player2 p2;
    
    p1.makeMove();
    p2.makeMove();

    p1.checkWin();
    p2.checkWin();

}