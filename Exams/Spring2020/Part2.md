# Del 2
## Oppgave 2.1
```
template <typename T>
void set_num(T input) {
    num = int(input);
}
```

## Oppgave 2.2
rand() funksjonen benytter seg av en algoritme som benytter et argument for å generere et tilfeldig tall. Denne algoritmen er deterministisk, som vil si at den genererer samme tall for `srand(0)`, men for srand(time(nullptr)) vil den ta utgangspunktet i tiden akkurat under kjøring, og den såkalte "seed"-en vil være forskjellig for hver gang.


## Oppgave 2.3
```
class X {};
void main() {
    auto list = std::unique_ptr<X[]>(new X[1'000'000]()); // The ' character can be used to separate digits into groups to make them more readable
}
```


## Oppgave 2.4
```
void MyCustomArray::setValueAtIndex(unsigned int index, DataType value) {
    contents.at(index) = value;
    return;
}
```


## Oppgave 2.5
Et `set` er en kontainer som kun inneholde ett element av hver type. Det kan være nyttig å benytte `set` når du kun er interessert i innholdet i konteineren og ikke hvor mange instanser det er av hvert element.