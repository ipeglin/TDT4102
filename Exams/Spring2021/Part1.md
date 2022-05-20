# Part 1

## Oppgave 1.1

### Deloppgave a)

Kjøretidsfeil

### Deloppgave b)

Syntaksfeil

### Deloppgave c)

Logisk feil

### Deloppgave d)

Type-feil

## Oppgave 1.2

Linje 16. Skal være `win++;`

## Oppgave 1.3

### Deloppgave a)

```
constexpr unsigned int my_log2(unsigned int n ) {
    return ((n < 2) ? 1 : 1 + my_log2(n / 2));
}
```

### Deloppgave b)

- constexpr-funksjoner kan bare kalle andre funksjoner hvis de også er constexpr
- Bruk av constexpr kan åpne for verdi-avhengige kode-optimaliseringer
- Programytelsen kan noen ganger forbedres ved å beregne verdier på kompileringstidspunktet ved hjelp av constexpr

## Oppgave 1.4

### Deloppgave a)

Usant

### Deloppgave b)

Sant

### Deloppgave c)

Usant

### Deloppgave d)

Usant

## Oppgave 1.5

- Linje 14
  `row`vektoren skal inneholde `std::vector<int>` ikke `int`.
- Line 15 og 17
  `length()` er ikke en metode for `std::vector` i C++. Den riktige metoden ville vært `size()`.

## Oppgave 1.6

### Deloppgave a)

Sant

### Deloppgave b)

Usant. Man <u>kan</u> bruke denne løsningen i stedet for `map`, men det er ikke akkurat logisk å ville det.

### Deloppgave c)

Sant

### Deloppgave d)

Usant

### Deloppgave e)

Sant
