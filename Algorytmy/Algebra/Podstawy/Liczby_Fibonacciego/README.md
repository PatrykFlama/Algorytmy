[Wróć](../../../../../../)

# Liczby Fibonacciego

## Opis
Ciąg liczb Fibonacciego to ciąg a<sub>n</sub> = a<sub>n-1</sub> + <sub>n-2</sub>

## Algorytm
Podejście iteracyjne:
```cpp
int policz_fib_iter(int n){
    if(n == 0) return 0;

    int a = 1, b = 1;
    for(int i = 2;;i++){
        if(i == n) break;
        else {
            int buff = a;
            a = a+b;
            b = buff + b;
        }
    }
    
    return b;
}
```

Podejście rekurencyjne:
```cpp
int policz_fib_rek(int n = 1, int a = 1, int b = 1){
    if(n == 0) return 0;
    if(n > 0){
        return policz_fib_rek(n--, a+b, a);
    }
    return b;
}
```

Podejście z macierzami i szybkim potęgowaniem T(log n)
```cpp
pair<int, int> policz_fib(int n){   // <Fib_n, Fib_n+1>
    if(n == 0) return 0;

    int f = policz_fib(sqrt(n));
    int a = f.first * (2 * f.second + f.first);
    int b = f.first*f.first + f.second*f.second;
    if(n%2) return{b, a+b};
    else return{a, b};
}
```