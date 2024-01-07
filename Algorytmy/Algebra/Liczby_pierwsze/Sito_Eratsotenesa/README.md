[Wróć](../../../../../../)

# Sito Eratsotenesa

## Działanie
Algorytm z ciągu arytmetycznego _r = 1_ wydzedza liczby pierwsze, wykreślając każdy iloczyn liczby (_>1_) z listy liczb pierwszych.
Algorytm można nieznacznie przyspieszyć (dwukrotnie), wykluczając liczby parzyste z obliczeń.  
Dodatkowo można lekko zmienić implementację i zastosować maski bitowe, aby zmniejszyć zużycie pamięci.

## Algorytm
```cpp
bool[] sito(int max_liczba){
    max_liczba++;
    bool sito[max_liczba];
    fill(sito, sito+max_liczba, true);

    for(int i = 2; i < max_liczba; i++){
        if(sito[i] == true){
            for(int j = i*2; j < max_liczba; j+=i){
                sito[j] = false;
            }
        }
    }

    return sito;
}
```
