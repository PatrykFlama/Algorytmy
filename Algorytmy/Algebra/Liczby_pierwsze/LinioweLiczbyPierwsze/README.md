[Wróć](../../../../../../)

# Liczby pierwsze na przedziale w czasie liniowym

## Algorytm
Naszym celem jest policzenie minimalnego pierwszego dzielnika dla każdej liczby z przedziału _[2, n]_, będziemy go zapisywać w tablicy _lp_ (ang. least prime). Na początku tablica _lp_ jest wyzerowana, czyli na początku zakładamy że wszystkie liczby są pierwsze.  
Będziemy też potrzebować listy liczb pierwszych _pr_.  

Iterujemy się po liczbach z naszego przedziału _[2, n]_:
* $\textrm{lp}[i] = 0$ $\iff$ _i_ jest liczbą pierwszą $\iff$ $\iff$ _i_ nie ma żadnego mniejszego dzielnika, więc ustawiamy _lp[i] = i_ oraz dodajemy je do _pr_
* $\textrm{lp}[i] \neq 0$ $\iff$ _i_ jest liczbą złożoną z minimalnym dzielnikiem pierwszym = _lp[i]_  

Następnie dla liczby pierwszej _p_ (liczby z _pr_) mniejszej od _lp[i]_ (czyli aktualnego najmniejszego piewrszego dzielnika) ustawiamy _lp[i*p] = p_  

## Implementacja
```cpp
const int N = 1e7+5;
int lp[N+1];
vector<int> pr;

for (int i = 2; i <= N; ++i) {
    if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back(i);
    }
    for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i*pr[j] <= N; ++j)
        lp[i*pr[j]] = pr[j];
}
```

## Złożoność
Złożoność czasowa: $\mathcal{O}(n)$  
Złożoność pamięciowa: $\mathcal{O}(n)$  
Problem? W przeciwieństwie do sita Eratostenesa nie możemy zmiejszyć zużycia pamięci korzystając z masek bitowych.
