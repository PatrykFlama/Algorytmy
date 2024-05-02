#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;  // adjacency list
vector<bool> vis;           // visited vertices

void dfs_recursive(int v) {
    vis[v] = true;
    for (int i : graph[v]) {
        if (!vis[i]) dfs_recursive(i);
    }
}


void dfs_iterative(int v) {
    stack<int> s;
    s.push(v);
    vis[v] = true;

    while (!s.empty()) {
        int v = s.top();
        s.pop();
        for (int i : graph[v]) {
            if (!vis[i]) {
                vis[i] = true;
                s.push(i);
            }
        }
    }
}



int main(){}