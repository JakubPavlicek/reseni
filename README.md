# Jakub Pavliček

## task01
Zatím nic.

## task02
Opsáno, doplnit postup (slovně)

Doplněno o postup

## task03
Kód funguje

## task04
Kód funguje - "cout" jsem odstranil a nahradil ho "puts()", kterej vypíše mnou zadané pole
            - odstranil jsem "virtual void whatDoesItSay()" a vrátil jsem zpět "virtual const char whatDoesItSay()"

## task05
Kód funguje

## hra
Kód funguje

## task06
Kód funguje - využil jsem Dependency Inversion Principle, což je to, že by velmi důležité nebo vysoce postavené objekty neměly               záviset na nedůležitých či níže postavených objektech(implementacích). V mým tasku06 tento princip využívám na to, že třída Enemy použije funkci Tell() ze tříd Ninja a Monster, aniž by tyto 2 třídy přímo dědily z hlavní(vysoce postavené)
třídy Enemy. Je to vlastně takový úspornější způsob psaní kódu, že prostě stačí jednou definovat nějakou funkci a tuto funkci
pak použít na všech ostatních třídách. Další z příkladů by byl třeba nějakej Manažer firmy, ten přece nebude dělat takový ty
podprůměrný práce jako umejvání podlahy, řešení financí a tak, ale na každou tuto specifickou práci si najme někoho, kdo to
bude dělat za něj a manažer mu pak přesně řekne co může dělat.

## task07
Nevím jestli jsem správně pochopil zadání, ale podle toho jak jsem to pochopil, tak jsme měli jen určit velikost Vectoru2 a uložit to do "double" proměnné, pokud ano, tak kód funguje
JT: Velikost vektoru jsem měl na mysli matematicky, tj. v podstatě spočítání odvěsny. Z mého popisu to nebylo jednoznačné, akceptuju tedy vaše řešení. operátor násobení všem měl provést vektorový součin, ne skalární - prosím upravte.