#include <iostream>

using namespace std;

class TellDamage{ 
public:
    virtual string Tell()=0;
};

class Ninja : public TellDamage{
public:
    string Tell(){
        return "Ninja ti udelil 20 damage";
    }
};

class Monster : public TellDamage{
public:
    string Tell(){
       return "Monster ti udelil 50 damage";
    }
};

class Enemy{
public:
    TellDamage* tell;

    Enemy(TellDamage* damage){
        this->tell = damage;
    }
    string Tell(){
        return this->tell->Tell();
    };
};

int main(){

    Enemy* ninja = new Enemy(new Ninja);
    Enemy* monster = new Enemy(new Monster);

    cout << ninja->Tell() << "\n";
    cout << monster->Tell() << "\n";
}
