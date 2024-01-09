[Wróć](../../../../../)

# Szukanie punktów artykulacji
Przechodzimy przez graf za pomocą DFS i szukamy takich wierzchołków, dla których żaden z jego potomków nie ma krawędzi do przodka. Wtedy usuwając wierzchołek usuwamy całą spójną składową.  
Jedyny wyjątek w algorytmie mamy dla korzenia przeszukania, który jest punktem artykulacji jeśli ma więcej niż jednego potomka.

```cpp
int n; // number of nodes
vector<vector<int>> graph; // adjacency list of graph

vector<bool> visited(n, false);
vector<int> time_in(n, -1);     // time of entry into the vertex
vector<int> lowest_ancestor(n, -1);     // ancestor with the lowest time of entry
int timer = 0;

void dfs(int v, int ancestor = -1) {
    visited[v] = true;
    time_in[v] = lowest_ancestor[v] = timer++;

    for (int to : graph[v]) {
        if (to == ancestor) continue;
        if (visited[to])
            lowest_ancestor[v] = min(lowest_ancestor[v], time_in[to]);
        else {
            dfs(to, v);
            lowest_ancestor[v] = min(lowest_ancestor[v], lowest_ancestor[to]);
            // if next vertex has a lower ancestor, when we would remove edge (v, to) vertex to would still be connected to higher ancestor, so edge (v, to) is not a bridge
            // otherwise vertex v is the highest (and only) ancestor of vertex to, so edge (v, to) is a bridge
            if (lowest_ancestor[to] >= time_in[v] && ancestor != -1)
                ARTICULATION_POINT(v);  // v is an articulation point
        }
    }

    if (ancestor == -1 && graph[v].size() > 1)
        ARTICULATION_POINT(v);  // v is an articulation point
}

void find_bridges() {
    for (int i = 0; i < n; ++i)
        if (!visited[i])
            dfs(i);
}
```

