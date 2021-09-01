[Wróć](../../../../../..)

# Dijkstra

## Zasada działania algorytmu
Mamy tablicę *d[]*  w której trzymamy dla każdego indeksu wierzchołka *v* długość od wierzchołka startowego *s* do *v*. Na początku *d[s]* = 0, a wszystkie pozostałe komórki są równe nieskończoności. Dodatkowo mamy też tablicę odwiedzonych wierzchołków *visited*. 

Algorytm ma **n** iteracji i działa na bazie dfs'a. Podczas każdej wybierany jest wierzchołek *v*, który nie został jeszcze odwiedzony i ma najmniejszą wartość *d[v]* (odległość). Podczas pierwszej iteracji zostaje wybrany wierzchołek startowy. 
Wybrany wierzchołek *v* zostaje oznaczony jako odwiedzony. Przechodzimy przez wszystkich jego sąsiadów i dla każdego algorytm **próbuje poprawić jego wynik o *d[v]* + waga ścieżki sąsiad-wierzchołek**. 

Wyniki wierzchołków powinny już być policzone, warto zauważyć, że wierzchołki niepołączone z grafem pozostaną z wartością nieskończoną. 

## Odczytywanie najkrótszych dróg
Aby odczytać najkrótszą trasę musimy przechowywać dodatkowe informacje. Stworzymy do tego tablicę przodków *p[]*, którą będziemy zmieniać przy aktualizacji wyniku w wierzchołku. 
By odczytać ścieżkę z danego wierzchołka *v* wystarczy rekurencyjnie odczytywać *p[v]* i przypisywać *v = p[v]*, dopóki nie dojdziemy do wierzchołka startowego.