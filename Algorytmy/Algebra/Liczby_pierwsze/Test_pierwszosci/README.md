[Wróć](../../../../../../)

# Test pierwszości

## Działanie
Aby sprawdzić czy dana liczba _n_ jest liczbą pierwszą, należy sprawdzić czy dzieli się tylko przez 1 i przez samą siebie. Jednak z racji iż największa liczba, przez którą _n_ może być podzielna to _sqrt(n)_, wystarczy sprawdzić tylko liczby ze zbioru _<2, sqrt(n)>_.

## Algorytm
```cpp
bool czy_pierwsza(int n){
    for(int i = 2; i*i <= n; i++){
        if(n%i==0) return false;
    }
    return true;
}
```
