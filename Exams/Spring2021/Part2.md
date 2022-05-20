# Libraries

```
#include <iostream>
#include <string>
#include <vector>
#include <set>
```

# Oppgave 2.1

```
template <typename T>
void print_container(const T &container)
{
    for (auto itr = container.begin(); itr != container.end(); ++itr)
    {
        std::cout << *itr << std::endl;
    }
}
```

# Oppgave 2.2

## Deloppgave a)

Funksjonen f tar inn en tekststreng. Deretter separerer den tekststrengen ved alle instanser av tegnet `char d`.
De separerte segmentene legges til i en vektor c. Til slutt printes alle elementene ut på hver sin linje

## Deloppgave b)

```
is
this
hard?
```

# Oppgave 2.3

## Deloppgave a)

En kunne ha benyttet en enum class for å definere retningene. Et eksempel er
`enum class Direction {Left = 0, Right, Up, Down};`

## Deloppgave b)

Se deloppgave a)

```
// Prettier code
enum class Director {
    Left = 0,
    Right,
    Up,
    Down
};
```

# Oppgave 2.4

## Deloppgave a)

Klassen bruker ikke smart pointers og har ikke en destruktør. Derfor vil det resultere i en minnelekkasje om antall iterasjoner øker.

## Deloppgave b)

```
~Matrix() {
    delete[] data;
}
```

# Oppgave 2.5

## Deloppgave a)

Alloker riktig datamengde for vec med en gang instansen lages i linje 8

## Deloppgave b)

```
StaticLengthVector(size_t size) :
    size{size} {
    vec.reserve(size);
}
```

# Oppgave 2.6

## Deloppgave a)

```
Bjarne_cool
Bell_cool
Ford_cool
```

## Deloppgave b)

Dette ville ikke endret vektoren i det hele tatt.
Dette vil gi en kompileringsfeil siden det er en konstant som blir forsøkt endret.

## Deloppgave c)

Det vil skrives ut det samme som i deloppgave a).
Dette vil også endre vektoren til `{Barne_cool, Bell_cool, Ford_cool}`.
