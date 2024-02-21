[Wróć](../../../../../)

# Algorytm Kosaraju (szukanie silnie spójnych składowych)
Algorytm ma 2 fazy opierające się na DFS:  

Tworzymy stos oraz tablicę visited, przechodzimy po grafie za pomocą DFS, przy wychodzeniu z wierzchołka dodajemy go na stos.
W drugiej fazie będziemy potrzebować drzewa z odwróconymi kierunkami krawędzi, po nim będziemy teraz chodzić za pomocą DFS.   
Dopóki są wierzchołki na stosie:  
* Bierzemy pierwszy nieodwiedzony wierzchołek
* Przechodzimy od niego za pomocą DFS i każdy odwiedzony wierzchołek dodajemy do aktualnej składowej

czas $O(V+E)$

