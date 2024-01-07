[Wróć](../../../../../../)

# Algorytm Floyda-Warshalla
Znajduje dla każdej pary wierzchołków najkrótszą ścieżkę między nimi. Ujemne wagi zezwolone.  
Złożoność: O(n^3)


```cpp
vector<vector<int>> graph;
vector<vector<int>> distance;   // distance[i][j] - shortest path from i to j

void floyd_warshall() {
    int n = graph.size();
    distance.assign(n, vector<int>(n, INT_MAX));

    // at first we copy weights of edges from graph
    for (int i = 0; i < n; i++) {
        distance[i][i] = 0;
        for (auto e : graph[i]) {
            distance[i][e.first] = e.second;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // for each pair of vertices, check all vertices of graph and check if it improves the result
                if (distance[i][k] < INT_MAX && distance[k][j] < INT_MAX) {
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
    }
}

```

