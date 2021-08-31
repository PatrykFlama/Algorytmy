[Wróć](../../../../../..)

# Rozszerzony algorytm Euklidesa

Rozszerzona wersja algorytmu Euklidesa pozwala rozwiązać równanie: $NWD(a, b) = a * x + b * y$ wyznaczając wartości *x* i *y*.

## Algorytm
$x = y_1$ \
$y = x_1 - y_1*\lfloor \frac{a}{b} \rfloor$

## Wyprowadzenie algorytmu
Dla ułatwienia zapisu $n = NWD(a, b)$. \
Aby uzyskać algorytm pójedziemy 'wstecz' podstawowego algorytmu Euklidesa, który kończy się z $a = n; b = 0$, czyli $n * 1 + 0 * 0 = n$ => $x = 1; y = 0$. \
Załóżmy że znaleźliśmy współczynniki $x_1$ i $y_1$ dla $(b, a \bmod b)$: \
$b*x_1 + (a \bmod b)*y_1 = n$ \
$a*x + b*y = n$ \
$a \bmod b = a - \lfloor{\frac{a}{b}}\rfloor$ \
$n = b*x_1 + (a \bmod b)*y_1=b*x_1 + (a - \lfloor{\frac{a}{b}}\rfloor)*y_1$ \
$n = a*y_1 + b*(x_1 - y_1*\lfloor \frac{a}{b} \rfloor)$ \
$\{ x = y_1 \\ \{ y = x_1 - y_1*\lfloor \frac{a}{b} \rfloor$

## Implementacja
Wersja rekurencyjna:

```cpp
int nwd(int a, int b, int& x, int& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int n = nwd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);

    return n;
}
```
