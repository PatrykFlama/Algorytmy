# Knuth Morris Pratt algorithm (KMP)
## Działanie ogółem
Oblicza tablicę prefikso-sufiksów w czasie liniowym (dzięki czemu możemy znaleźć powtórzenia wzorca w tekście)

## Działanie konkretniej
Prefikso-sufiks to takie podsłowo, które jest zarówno prefiksem danego słowa, jak i jego sufiksem. 
Prefikso-sufiks właściwy, podobnie jak prefiks właściwy i sufiks właściwy, to taki prefikso-sufiks, który nie jest całym słowem.
Ten algorytm opiera się na obliczaniu tablicy najdłuższego prefikso-sufiksu właściwego danego słowa.
Dzięki temu jesteśmy w stanie znaleźć dane słowo w tekście, nawet jeżeli jest ono zlepkiem samego siebie, np: *abab* w *abababababab* powtarza się 5, a nie 3 razy.
Tablica którą oblicza to tablica π (powód nazwy nieznany), a czas jej obliczania jest liniowy.

## Implementacja
Wpierw znajdujemy prefikso-sufiksy w wyrazie wyszukiwanym. Iterujemy się po jego literach zapisując ich numer jako prefiks słowa (dla słowa _abcdabca_ tablicą wynikową jest _00001231_). 
Następnie iterujemy się po tekście sprawdzając ile liter się powtarza (liczymy prefiksy wyrazu szukanego). Jeżeli litery się różnią, nie cofamy się w wyszukiwanym tekście, a stwierdzamy ile liter z poprzedniego prefiksu się zgadza z następnym (tablica _pi_ i proste porównanie).

## Złożoność czasowa
T(O) = długość wyrazu + długość tekstu

## Złożoność pamięciowa
S(O) = długość wyrazu + długość tekstu
