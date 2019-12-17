#include <cstdio>
#define byte unsigned char

byte data[8]; // proměnná byte je unsigned char a nastaví se na maximální počet bytů na 8

byte flipBits(byte number){ // funkce flipBits mi přehodí bity, takžě např. místo 0 bude 1
	byte result = 0;   // proměnná nazvaná result bude defaultně na 0
	for(int i=0; i<8; ++i) {   // nastavíme proměnnou celého čísla pomocí int a zadáme určité parametry pro proměnnou i
		bool bit = number & (1<<i);   // proměnná bool dělá to, že v ní může být pouze 0 nebo 1, špičatý závorky nam posouvají bity
		result |= bit<<(7-i);
	}
	return result;
}

void readDate(int* y, int* m, int* d, byte b1, byte b2) // funkce void nevrací žádnou hodnotu
{
    *m = b2 & 0b1111;   // nastavení měsíce v datumu
    *d = b2>>4 | ((b1 & 0b1)<<4);   // nastavení dne v  datumu
    *y = flipBits(b1>>1)>>1;    // nastavení roku v datumu s funkcí flipBits, která v tomto případě také posouvá bity
}

int main()
{
    FILE * fd = fopen("task02.dat", "rb");  // otevření souboru pro čtení bitů

    fread(data, 8, 1, fd); // funkce pro čtení ze souboru
    int y, m, d; // proměnné, které budou pouze v celých číslech
    readDate(&y, &m, &d, data[0], data[1]); // funkce na čtení datumu
    printf ("John Doe se narodil: %d.%d.%d\n", d, m, y+1900); // vytiskne do konzole zadaný text a datum kdy se daný člověk narodil

    fread(data, 8, 1, fd);
    readDate(&y, &m, &d, data[0], data[1]);
    printf ("Sam Sepiol se narodil: %d.%d.%d\n", d, m, y+1900);
}
