/*
  Tento příklad demonstruje přetěžování operátorů << a >> knihovny iostream.
  Zapíšeme-li "cout << x << y", pak se to vyhodnotí jako "((cout << x) << y)".
  Tedy operátor << má na levé straně objekt ostream a na pravé straně to, co má vypsat.
  Návratová hodnota je objekt na levé straně (cout), po "cout<<x" se tedy provede "cout<<y".
  Knihovny iostream definuje objekt ostream "cout" pro standardní výstup a "cin" pro vstup".
  Podobně funguje i stringstream, ale vstup a výstup je zde řetězec.
  Všimněte si operátorů << a >> definovaných níže a jejich použití v metodě main.
  Tyto funkce lze také použít pro načítání Vector2 z řetězce.
  Protože stringstream dědí z iostream, zdědí se a fungují stejně jako se standardním vstupem.
  Nyní se podívejte na tento obrázek: http://www.cplusplus.com/reference/iolibrary/
  knihovna fstream, která čte a zapisuje ze souboru, funguje stejně.
  Použijte tedy tentýž kód pro ukládání Vector2 do souboru a načítání Vector2 ze souboru.
  Jediný rozdíl je v konstruktoru, který očekává jméno souboru, např.
  fstream data("data.txt");
*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

struct Vector2 {

    double x;
    double y;

    Vector2(double x, double y)
        : x(x), y(y)
    {  
    }

    Vector2()
        : x(0), y(0)
    {
    }
};

std::ostream& operator<<(std::ostream& output, const Vector2& v) {
    output << "[" << v.x << "," << v.y << "]";
    return output;
}

std::istream& operator>>(std::istream& input, Vector2& v) {
    char c;
    input >> v.x >> c >> v.y;
    return input;
};

class Entity
{
public:
    int m_X;
    std::string m_Str;

    Entity(int x, std::string str)
        : m_X(x), m_Str(str)
    {
    }
    Entity()
        : m_X(55), m_Str("ahoj")
    {
    }

    friend std::ostream& operator<<(std::ostream& output, const Entity& entity);
    friend std::istream& operator>>(std::istream& input, Entity& entity);

};

std::ostream& operator<<(std::ostream& output, const Entity& entity)
    {
        output << "[Class] cislo je: " << entity.m_X << " [Class] string je: " << entity.m_Str;
        return output;
    }

std::istream& operator>>(std::istream& input, Entity& entity)
    {
        std::cout << "Zadej cislo: ";
        input >> entity.m_X;
        std::cout << "Zadej string: ";
        input >> entity.m_Str;
        return input;
    }

int main() {
    Vector2 a;

    // čtení a výpis Vector2 ze standardního IO
    std::cin >> a;
    std::cout << "a = " << a << std::endl;

    // čtení a výpis Vector2 z řetězce
    std::stringstream ss;
    ss << "3.14,7";
    ss >> a;
    std::cout << "a = " << a << std::endl;

    // doplňte čtení a výpis Vector2 ze souboru

    double temp_X = a.x;
    double temp_Y = a.y;

    std::ifstream ifile("data2.txt");

    if(ifile)
    {
        ifile >> temp_X >> temp_Y;
        std::cout << "Data Vectoru2 vložená do souboru: " << a << std::endl;
        ifile.close();
    }
    else
        std::cout << "Nepodařilo se otevřit soubor" << std::endl;

    std::ofstream ofile("data2.txt");

    if(ofile)
    {
        ofile << a;
        std::cout << "Přečtená data Vectoru2 ze souboru: " << a << std::endl;
        ofile.close();
    }
    else
        std::cout << "Nepodařilo se otevřit soubor" << std::endl;
    
    // Pokuste se vytvořit vlastní třídu a definujte na ní operátory << a >>
    Entity e(5, "pes");
    std::cout << e << std::endl;
    std::cin >> e;
    std::cout << "Po načtení Classy jsou hodnoty takovéhle: "; 
    std::cout << e << std::endl;
}   