#include <bits/stdc++.h>
using namespace std;
vector< vector<int> > graph;
vector<bool> vis;


void dfs(int vortex){
    vis[vortex] = true;
    for(int i : graph[vortex]){
        if(!vis[i]) dfs(i);
    }
}


int main(){
    int edges, verticies;
    cout << "Input number of edges and verticies:\n";
    cin >> edges >> verticies;
    graph.resize(edges);
    vis.resize(edges);

    cout << "Now gimme those edges:\n";
    for(int i = 0; i < edges; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    fill(vis.begin(), vis.end(), false);
    for(int i = 0; i < graph.size(); i++) if(!vis[i]) dfs(i);
}