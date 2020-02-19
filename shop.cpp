#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Output{
public:
    int id, cena; 
    int y, x;
    string line, line2;
    stringstream ss;
    stringstream ss2;

    int get_y(int ore){
        y = ore;
        return y;
    };
};

class Item : public Output{
public:
    string item;
    string to_string(){
        ifstream ifile("items.txt"); 

        while(!ifile.eof()){
            item = "";
            getline(ifile, line);
        
        for(int e = 0; e < line.size(); e++){
            if(line[e] >= 48 && line[e] <= 57 || line[e] == ';'){
                continue;
            }
            item += line[e];
        }

        ss >> line;
        if(stringstream(line) >> id)
        if(y == id){
            return item;
        }

        }
        
    };
};

class Price : public Output{
public:
    string price;
    string to_price(){
        ifstream ifile("items.txt");

        while(!ifile.eof()){
            price = "";
            getline(ifile, line2);
        
        for(int r = 0; r < line2.size(); r++){
            if(line2[r] >= 97 && line2[r] <= 122 || line2[r] == ';'){
                continue;
            }
            price += line2[r];
        }

        ss >> line2;
        if(stringstream(line2) >> id)
        if(y == id){
            price.erase(0, 1);
            return price;
        }

        }
        
    };

};

class Cart : public Item, public Price{
public:
    void say(Item& i, Price& p){
        cout << i.to_string() << " " << p.to_price() << endl;
    }

};

int main(){

    int var_y;

    cout << "Zadej ID: ";
    cin >> var_y;

    Output out;
    out.get_y(var_y);

    Item it;
    it.get_y(var_y);

    Price pr;
    pr.get_y(var_y);

    Cart* cart = new Cart();
    cart->say(it, pr);
    delete cart;
}
