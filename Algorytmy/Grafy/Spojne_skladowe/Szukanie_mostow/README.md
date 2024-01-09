[Wróć](../../../../../)

# Szukanie mostów
Przechodzimy przez graf za pomocą DFS, szukamy takich krawędzi, że żaden z potomków wierzchołka nie ma krawędzi do przodka. Wtedy usuwając krawędź usuwamy całą spójną składową.

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
            if (lowest_ancestor[to] > time_in[v])
                BRIDGE(v, to);  // v-to is a bridge
        }
    }
}

void find_bridges() {
    for (int i = 0; i < n; ++i)
        if (!visited[i])
            dfs(i);
}
```

