[Wróć](../../../../../../)

# Test pierwszości

## Rozwiązanie liniowe (pierwiastkowe)
Aby sprawdzić czy dana liczba _n_ jest liczbą pierwszą, należy sprawdzić czy dzieli się tylko przez 1 i przez samą siebie. Jednak z racji iż największa liczba, przez którą _n_ może być podzielna to _sqrt(n)_, wystarczy sprawdzić tylko liczby ze zbioru _<2, sqrt(n)>_.

### Algorytm
```cpp
vector<int> rozklad(int liczba){
    vector<int> czynniki;

    for(int i = 2; i*i <= liczba; i++){
        while(liczba % i == 0){
            czynniki.push_back(i);
            liczba /= i;
        }
    }

    return czynniki;
}
```

## Optymalizacja pierwszego podejścia
Pierwsze podejście możemy w prosty sposób zoptymalizować integrując do algorytmu sito erastotenesa - wtedy zamiast sprawdzać wszystkie liczy z przedziału _<2, sqrt(n)>_ wystarczy sprawdzić tylko liczby pierwsze z tego przedziału. Te podejście wymaga jednak preprocessingu, aby wyliczyć liczby pierwsze.

```cpp
vector<int> liczby_pierwsze;        // załóżmy że są one już wyliczone

vector<int> rozklad(int liczba){
    vector<int> czynniki;

    for(int i : liczby_pierwsze){
        if(i*i > liczba)
            break;

        while(liczba % i == 0){
            czynniki.push_back(i);
            liczba /= i;
        }
    }
}
```
