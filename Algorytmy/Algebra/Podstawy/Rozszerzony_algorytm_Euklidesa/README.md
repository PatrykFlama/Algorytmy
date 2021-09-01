[Wróć](../../../../../..)

# Rozszerzony algorytm Euklidesa

Rozszerzona wersja algorytmu Euklidesa pozwala rozwiązać równanie: <img src="https://latex.codecogs.com/svg.image?NWD(a,%20b)%20=%20a%20*%20x%20+%20b%20*%20y" style="filter:invert(1)"> wyznaczając wartości *x* i *y*.

## Algorytm
<img src="https://latex.codecogs.com/svg.image?x%20=%20y_1" style="filter:invert(1)"> \
<img src="https://latex.codecogs.com/svg.image?y%20=%20x_1%20-%20y_1*\lfloor%20\frac{a}{b}%20\rfloor" style="filter:invert(1)">

## Wyprowadzenie algorytmu
Dla ułatwienia zapisu <img src="https://latex.codecogs.com/svg.image?n%20=%20NWD(a,%20b)" style="filter:invert(1)">. \
Aby uzyskać algorytm pójedziemy 'wstecz' podstawowego algorytmu Euklidesa, który kończy się z <img src="https://latex.codecogs.com/svg.image?a%20=%20n;%20b%20=%200" style="filter:invert(1)">, czyli <img src="https://latex.codecogs.com/svg.image?n%20*%201%20+%200%20*%200%20=%20n" style="filter:invert(1)"> => <img src="https://latex.codecogs.com/svg.image?x%20=%201;%20y%20=%200" style="filter:invert(1)">. \
Załóżmy że znaleźliśmy współczynniki <img src="https://latex.codecogs.com/svg.image?x_1" style="filter:invert(1)"> i <img src="https://latex.codecogs.com/svg.image?y_1" style="filter:invert(1)"> dla <img src="https://latex.codecogs.com/svg.image?(b,%20a%20\bmod%20b)" style="filter:invert(1)">: \
<img src="https://latex.codecogs.com/svg.image?b*x_1%20+%20(a%20\bmod%20b)*y_1%20=%20n" style="filter:invert(1)"> \
<img src="https://latex.codecogs.com/svg.image?a*x%20+%20b*y%20=%20n" style="filter:invert(1)"> \
<img src="https://latex.codecogs.com/svg.image?a%20\bmod%20b%20=%20a%20-%20\lfloor{\frac{a}{b}}\rfloor" style="filter:invert(1)"> \
<img src="https://latex.codecogs.com/svg.image?n%20=%20b*x_1%20+%20(a%20\bmod%20b)*y_1=b*x_1%20+%20(a%20-%20\lfloor{\frac{a}{b}}\rfloor)*y_1" style="filter:invert(1)"> \
<img src="https://latex.codecogs.com/svg.image?n%20=%20a*y_1%20+%20b*(x_1%20-%20y_1*\lfloor%20\frac{a}{b}%20\rfloor)" style="filter:invert(1)"> \
<img src="https://latex.codecogs.com/svg.image?\{%20x%20=%20y_1%20\\%20\{%20y%20=%20x_1%20-%20y_1*\lfloor%20\frac{a}{b}%20\rfloor" style="filter:invert(1)">

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
