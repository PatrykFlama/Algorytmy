[Wróć](../../../../../..)

# Szybkie potęgowanie

## Na czym polega?
Zwykłe podnoszenie *n* do *k* potęgi jest naiwnym mnożeniem $n^k=n*n*n* \ldots * n$. \
Aby przyspiezsyć ten proces będziemy rozkładać potęgę: \
$n^k = (n^{k/2}) * (n^{k/2})$, gdy $k|2$ \
$n^k = (n^{k/2}) * (n^{k/2}) * n$, gdy $k+1|2$

* Rozwiązanie rekurencyjne
```c++
int szybkie_potegowanie(int n, int k) {
    if (k == 0)
        return 1;

    int res = szybkie_potegowanie(n, k / 2);
    
    if (k % 2)
        return res * res * n;
    else
        return res * res;
}
```

* Rozwiązanie iteracyjne
```c++
int binpow(int n, int k) {
    int res = 1;

    while (k > 0) {
        if (k & 1)		// czy nieparzyste
            res = res * n;
        n = n * n;
        k >>= 1;		// k /= 2
    }

    return res;
}
```
