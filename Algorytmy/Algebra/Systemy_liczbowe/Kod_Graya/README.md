[Wróć](../../../../../../)

# Kod Graya

## Działanie
Kod Graya to pętla po maskach bitowych, w których z jednej iteracji na drugą zmienia się tylko jeden bit. Można to wykorzystać do usprawnienia zwykłej pętli i zamiast liczyć wynik dla maski od początku za każdym razem, jedynie zmieniać poprzedni (np sumy po tablicy). 
Innymi słowy - kod Graya to przetworzenie zwykłej maski (takiej, jaką mamy przy iteracjach z dodawaniem) prostym działaniem, tak aby zmieniał się tylko jeden bit w masce.

## Złożoność czasowa
![](https://latex.codecogs.com/svg.image?\color%20{white}O(n))

## Złożoność pamięciowa
stała

# Kod

```cpp
for(int i = 0; i < n; i++){
    int liczbaGreya = (i >> 1)^i;
    cout << bitset<4>(liczbaGreya).to_string() << '\n';
    //i tu jeszcze trzeba znaleźć ktr liczbe zmieniasz i ja zmienic
}
```
