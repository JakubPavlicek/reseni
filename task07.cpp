#include <cstdio>
#include <iostream>

/*
	V C++ jsou operátory funkce jako každá jiná.
	Vector2 obsahuje přetypovávací operátor char*(), který se volá tehdy, když NĚČEMU typu char* přiřadíme hodnotu Vector2.
    Pokud Vector2 obsahuje přetypovávací operátor, zavolá se tato funkce. Tento operátor tedy funguje podobně jako metoda toString() z jiných jazyků.
    Napište operátor double(), který vrátí velikost Vector2.
*/
class Vector2
{
protected:
	char buffer[16];
public:
	int x;
	int y;

	Vector2(int a, int b) 
        : x(a), y(b)
    {
	}

	operator char*()
    {
		snprintf(buffer, 15, "[%d,%d]", x, y);
		return buffer;
	}

    operator double()
    {
        return sizeof(Vector2);
    }
};

/*
	Podobně fungují aritmetické operátory, které lze zapisovat infixově - operátor uprostřed, např a*b - to je jenom jiný zápis a.operator*(b).
    Z toho ale plyne, že lze použít např. v*3, ale už ne 3*v. Tento problém vyřešíme ve třídě Vector2b.
*/
class Vector2a : public Vector2
{
public:
	using Vector2::Vector2; // použij konstruktor pro Vector2

	Vector2a operator*(int n)
    {
		return Vector2a(n*x, n*y);
	}
};

/*
	Vector2b řeší nedostatky Vector2a pomocí níže uvedené globální funkce.
    Implementujte do této třídy také operátor pro vektorový součin (tj. násobení vektoru vektorem)
*/
class Vector2b : public Vector2
{
public:
	using Vector2::Vector2;
	
	Vector2b operator*(int n)
    {
		return Vector2b(n*x, n*y);
	}
	
	Vector2b operator*(Vector2b& other)
	{
        return Vector2b(this->x*other.x, this->y*other.y);
    }
};

// globální funkce: operator*(a,b) je totéž, co a*b
Vector2b operator*(int n, Vector2b& v)
{
	return v * n;
}

int main()
{
//	Vector2 v1 = {2,4}; // inicializace pomocí seznamu, od C++11
//	Vector2 v1 {2,4}; // přímá inicializace členů, styl C
	Vector2 v1(2,4); // implicitní volání konstruktoru
	puts(v1); // funguje díky operátoru char*()

	Vector2a v2{2,4};
	puts(v2 * 3); // funguje díky operátorům char*() a *()
	// puts(3 * v2); // chyba, v2 musí být na levé straně

	Vector2b v3{2,4};
	puts(3 * v3);

    double vec2_size = v1;
    printf("Velikost Vectoru2 je: %.2f bytů\n", vec2_size);
}
