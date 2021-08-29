# Lowest Common Ancestor

## Działanie ogólnie
LCA oblicza najniży wierzchołek w drzewie, który jest przodkiem (ojcem, ojca, ojca, itd) obu danych wierzchołków. Jest to wierzchołek, przez który musimy przejść, jeżeli chcemy przejść najkrótszą możliwą trasą z punktu A do punktu B na drzewie.

## Działanie konkretniej (!TODO: to chyba nie działa z dfs?)
Tworzymy tablicę wierzchołków odwiedzonych i set wierzchołków wynikowych - posortowanych topologicznie. 
Losujemy dowolny nieodwiedzony wierzchołek i uruchamiamy w nim **dfs**. W dfs jeżeli wierzchołek nie ma już więcej nieodwiedzonych dzieci to dodajemy go do set'u. 
Powtarzamy dopóki nie odwiedzimy wszystkich wierzchołków.

## Złożoność czasowa


## Złożoność pamięciowa

