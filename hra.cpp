#include <iostream>
#include <bits/stdc++.h> 
#include <ncurses.h>

using namespace std;

class Game{
    public:
    virtual bool checkWin()=0;
    virtual void makeMove()=0;
    virtual void printResult()=0;

    int x = 0;
    int y = 0;

    bool turn = false;

    void startGame(){
        while(checkWin() == false){
            turn = !turn;
            makeMove();
        }
        printResult();
    }
};

class GuessGame : public Game{

public:
     
void makeMove(){
    switch(turn){
        case true :
            cout << "Player1 tipnul: ";
            x = getchar();
            if(getchar()=='\n' && sizeof(x)<= 5 && x >= 97 && x <= 122){
                cout << x << endl;
                break;
            }else{
                cout << "Player1 zadal spatne, zkus to znovu: ";
                x = getchar();
                cout << x << endl;
                break;
            };

        case false :
            cout << "Player2 tipnul: ";
            y = getchar();
            if(getchar()=='\n' && sizeof(y)<= 5 && y >= 97 && y <= 122){
                cout << y << endl;
                break;
            }else{
                cout << "Player2 zadal spatne, zkus to znovu: ";
                y = getchar();
                cout << y << endl;
                break;
            };
    }
};

void printResult(){
    if(x >= 97 && x <= 122 && x-8>y && x+8>y){
        cout << "Player1 won!" << endl;
    }
    if(y >= 97 && y <= 122 && y-8>x && y+8>x){
        cout << "Player2 won!" << endl;
    }
};

bool checkWin(){
    if(x-8>y && x+8>y && y != 0){ // TADY
        return true;
    }

    if(y-8>x && y+8>x && x != 0){
        return true;
    }

    if(x == 0 || y == 0){
        return false;
    }
};
};

int main(){

    GuessGame GGobj; 

    GGobj.startGame();

}
