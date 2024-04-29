[Wróć](../../../../../../)

# Sortowanie topologiczne
## Podejście z DFS
Przechodzimy za pomocą dfs i numerujemy wierzchołki od końca, korzystamy z własności, że gdy dfs wychodzi z wierzchołka to nie ma on więcej dzieci <=> możemy go dodać do wyniku.

## Podejście z BFS
W tym podejściu musimy policzyć liczbę wchodzących krawędzi do każdego wierzchołka.  
BFS puszczamy po kolei z wierzchołków które mają 0 wchodzących krawędzi. Odwiedzając dany wierzchołek możemy nadać mu adekwatny numer/koleność i usunąć z grafu, tym samym usuwając jego krawędzie (zmniejszyć adekwatnie wartości wierzchołkó wchodzących).  
Dodatkową przewagą tego algorytmu jest możliwość wykrywania cykli w grafie.