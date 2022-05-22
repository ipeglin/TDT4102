# Del 1
## Oppgave 1.1
`462529356`

`234569`

Dette skjer fordi et set kun kan inneholde ett av hvert element.


## Oppgave 1.2
Feil: `v.push_back(n);`

Korrekt: `(*v).push_back(n);` eller `v->push_back(n);`

Feilen var at det ble forsøkt å legge til en verdi til en vektor-peker, noe som ikke vil resultere i en kompileringsfeil.


## Oppgave 1.3
Fjern “continue” (linje 10)

Continue vil bryte ut av nåværende iterasjon i `while` løkken og derfor hoppe videre til den neste, der i nok engang kommer til å være odde, og derfor skrive ut "Fizz".


## Oppgave 1.4
* Usant
* Sant
* Sant
* Sant
* Usant


## Oppgave 1.5
```
# --- SayNiceThings.cpp ---------------------------
#include "SayNiceThings.h"
void saySomethingNice() {
    // empty
    std::cout << "You're doing great!!!" << std::endl;
    // empty
}
//empty
```

```
# --- SayNiceThings.h -----------------------------
// empty
#pragma once
#include <iostream>

void saySomethingNice();
```

```
# --- HelpfulRobot.cpp ----------------------------
#include "SayNiceThings.h"

int main(int argc, char** argv) {
    // empty
    saySomethingNice();
    // empty
}
// empty
```


## Oppgave 1.6
Jeg ville heller skrevet `Animal a{std::static_cast<Animal>(2)};` for å "caste" variablene fra en `int` til en `enum`.


## Oppgave 1.7
Delegating constructor


## Oppgave 1.8
