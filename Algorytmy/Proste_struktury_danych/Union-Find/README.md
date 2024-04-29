[wróć](../../../../../)

# Union-Find
Przy naiwnej implementacji funkcji _find_ osiągamy czas _O(n)_ ponieważ w najgorszym przypadku wysokość drzewa będzie rosła liniowo, ale można łatwo poprawić do _O(log n)_ 'spłaszczając' je przy każdej operacji _find_:  

```cpp
vector<int> parent;

int find_naive(int v) {
    while (v != parent[v])
        v = parent[v];
    return v;
}

int find(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}

void union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b)
        parent[b] = a;
}
```

