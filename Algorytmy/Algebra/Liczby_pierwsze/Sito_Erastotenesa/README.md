[Wróć](../../../../../../)

# Sito Erastotenesa

## Działanie
Algorytm z ciągu arytmetycznego _r = 1_ wydzedza liczby pierwsze, wykreślając każdy iloczyn liczby (_>1_) z listy liczb pierwszych.
Algorytm można w prosty sposób przyspieszyć dwukrotnie, wykluczając liczby parzyste z obliczeń.

## Algorytm
```cpp
bool[] sito(int len){
    bool sito[len];
    fill(sito, sito+len, true);

    for(int i = 2; i < len; i++){
        if(sito[i] == true){
            for(int j = i*2; j < len; j+=i){
                sito[j] = false;
            }
        }
    }
}
```
