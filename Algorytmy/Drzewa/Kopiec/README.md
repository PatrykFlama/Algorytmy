[Wróć](../../../../../../)

# Kopiec
Binarne drzewo spełniające następujące warunki:
- każdy liść ma taką samą głębokość, lub o jeden większą
- jest co najwyżej jeden wierzchołek z 1 liściem
- dla każdego wierzchołka `v` zachodzi pewna relacja _F_ między nim i jego synami, w tym przypadku będizemy analizować F: wartość w `v` jest większa od wartości w każdym z synów `v`  

najwydajniejszym sposobem na trzymanie kopca jest zwykła tablica, w której:
- aby przejść do lewego syna z wierzchołka `v` przechodzimy do wierzchołka `2*v`
- aby przejść do prawego syna z wierzchołka `v` przechodzimy do wierzchołka `2*v+1`
- aby przejść do ojca z wierzchołka `v` przechodzimy do wierzchołka `v/2`

## Naprawianie kopca
### Naprawianie kopca w dół $O(\log n)$
zaczynamy od zepsutego wierzchołka, sprawdzamy czy jest większy od swoich synów, jeśli nie to zamieniamy z większym z synów i przechodzimy z naprawą do syna  

### Naprawianie kopca w górę $O(\log n)$
zaczynamy od zepsutego wierzchołka, sprawdzamy czy jest większy od swojego ojca, jeśli nie to zamieniamy z ojcem i przechodzimy z naprawą do ojca

## Funkcje
zaimplementowanie operacji _fixUp_ i _fixDown_ pozwala w prosty sposób napisać następujące operacje:
* _insert_ - dodanie elementu do kopca $O(\log n)$
do najwcześniejszego wolnego miejsca dodajemy element, a następnie naprawiamy kopiec w górę od niego
* _pop_ - usunięcie korzenia kopca $O(\log n)$
  * wersja wolniejsza:  
zamieniamy korzeń z ostatnim elementem, usuwamy ostatni element, naprawiamy kopiec w dół od korzenia  
w takim podejściu wykonamy $2 \log n$ operacji, bo przenieśliśmy liścia (prawdopodobnie mała wartość) na korzeń (trzyma duże warości), więc prawdopodobnie przejdziemy po całej wysokości drzewa porównując 3 elementy za każdym razem (2 operacje)
  * wersja szybsza:  
wyrzucamy korzeń i dziurę 'naprawiamy' w dół, następnie zamieniamy dziurę z ostatnim elementem i go naprawiamy  
w takim podejściu wykonamy $\log n$ operacji do zniesienia dziury (porównujemy 2 zamiast 3 elementów - 1 operacja), ale najprawdopodobniej tylko kilka żeby naprawić liścia (8
* _top_ - zwrócenie korzenia kopca $O(1)$
po prostu zwracamy najwyższy element (korzeń)


# Kopiec minimax
przeanalizujemy 2 podejścia: dwa sklejone kopce oraz jeden kopiec z pomieszanymi warstwami (co druga to min/max)

## Podwójny kopiec
mamy 2 kopce, jeden z minimalnymi wartościami, drugi z maksymalnymi wartościami  
liczba najniższych liści obu kopców jest taka sama lub różni się o 1, dzięki czemu możemy łatwo przechodzić między nimi; porządek między liściami kopca jest zachowany  
operacje naprawiania w górę i w dół przechodzą przez liście (idą przez oba kopce)

## Kopiec z warstwami
wierzchołki na parzystych poziomach to minimalne wartości, na nieparzystych maksymalne  
adekwatnie - porządek zachowujemy dodatkowo między synami synów a ojcem