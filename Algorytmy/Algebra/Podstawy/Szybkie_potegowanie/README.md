[Wróć](../../../../../..)

# Szybkie potęgowanie

## Na czym polega?
Zwykłe podnoszenie *n* do *k* potęgi jest naiwnym mnożeniem <img src="https://latex.codecogs.com/svg.image?n^k=n*n*n*%20\ldots%20*%20n" style="filter:invert(1)">. \
Aby przyspiezsyć ten proces będziemy rozkładać potęgę: \
<img src="https://latex.codecogs.com/svg.image?n^k%20=%20(n^{k/2})%20*%20(n^{k/2})" style="filter:invert(1)">, gdy <img src="https://latex.codecogs.com/svg.image?k|2" style="filter:invert(1)"> \
<img src="https://latex.codecogs.com/svg.image?n^k%20=%20(n^{k/2})%20*%20(n^{k/2})%20*%20n" style="filter:invert(1)">, gdy <img src="https://latex.codecogs.com/svg.image?k+1|2" style="filter:invert(1)">

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
