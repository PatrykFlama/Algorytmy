[Wróć](../../../../../../)

# Dijkstra
## Opis
Algorytm pozwala na policzenie minimalnych odległości między wybranych początkowym wierzchołkiem a pozostałymi w grafie. Dodatkowo istnieje sposób na odczytanie tej najkrótszej ścieżki.

## Zasada działania algorytmu
Mamy tablicę *d[]*  w której trzymamy dla każdego indeksu wierzchołka *v* długość od wierzchołka startowego *s* do *v*. Na początku *d[s]* = 0, a wszystkie pozostałe komórki są równe nieskończoności. Dodatkowo mamy też tablicę odwiedzonych wierzchołków *visited*. 

Algorytm ma **n** iteracji i działa na bazie dfs'a. Podczas każdej iteracji wybierany jest wierzchołek *v*, który nie został jeszcze odwiedzony i ma najmniejszą wartość *d[v]* (odległość). Podczas pierwszej iteracji zostaje wybrany wierzchołek startowy.\
Wybrany wierzchołek *v* zostaje oznaczony jako odwiedzony. Przechodzimy przez wszystkich jego sąsiadów i dla każdego algorytm **próbuje poprawić jego wynik o *d[v]* + waga ścieżki sąsiad-wierzchołek**.

Wyniki wierzchołków powinny już być policzone, warto zauważyć, że wierzchołki niepołączone z grafem pozostaną z wartością nieskończoną. 

## Odczytywanie najkrótszych dróg
Aby odczytać najkrótszą trasę musimy przechowywać dodatkowe informacje. Stworzymy do tego tablicę przodków *p[]*, którą będziemy zmieniać przy aktualizacji wyniku w wierzchołku.\
By odczytać ścieżkę z danego wierzchołka *v* wystarczy rekurencyjnie odczytywać *p[v]* i przypisywać *v = p[v]*, dopóki nie dojdziemy do wierzchołka startowego.

```cpp
vector<vector<pair<int, int>>> graph;       // adjacency list

void dijkstra(int starting_node, vector<int> & distance, vector<int> & parent) {
    int n = graph.size();
    distance.assign(n, INT_MAX);
    parent.assign(n, -1);

    distance[starting_node] = 0;
    // we can use set or priority_queue
    // set<pair<int, int>> q;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.insert({0, starting_node});
    while (!q.empty()) {
        // int v = q.begin()->second;
        // q.erase(q.begin());

        int v = q.top().second;
        int dist_v = q.top().first;
        q.pop();
        if (dist_v != distance[v]) continue;        // if we have already updated v

        for (auto e : graph[v]) {
            int to = e.first;
            int len = e.second;

            if (distance[v] + len < distance[to]) {
                // q.erase({distance[to], to});
                distance[to] = distance[v] + len;
                parent[to] = v;
                q.push({distance[to], to});
                // q.insert({distance[to], to});
            }
        }
    }
}
```
