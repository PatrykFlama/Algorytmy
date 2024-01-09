#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

vector< vector< pair<int, int> > > graph;  //? graph[from] = {to, weight}
vector<int> dist;   //? dist from 0 to node
vector<bool> vis;   //? visited vertices
vector<int> parents;    //? we can use it to retrieve shortest path
#define to first
#define weight second


void reset_values(){
    dist[0] = 0;
    fill(dist.begin()+1, dist.end(), INT_MAX);
    fill(vis.begin(), vis.end(), false);
    fill(parents.begin(), parents.end(), -1);
}

void dijkstra(int start){
    priority_queue<pii, vector<pii>, greater<pii> > pq;        //? {dist, vortex} ascending sort
    pq.push({start, 0});

    while(!pq.empty()){
        // take verticie with the shortest distance, whish has not been visited
        int v = pq.top().second;
        pq.pop();
        if(vis[v]) continue;

        vis[v] = true;
        for(pii neighbour : graph[v]){       // iterate over all neighbours and try to improve their distance
            if(dist[neighbour.to] > dist[v]+neighbour.weight){
                dist[neighbour.to] = dist[v]+neighbour.weight;
                pq.push({dist[neighbour.to], neighbour.to});
            }
        }
    }
}


int main(){
    int n_verticies, n_edges;
    cout << "Input number of verticies and edges:\n";
    cin >> n_verticies >> n_edges;
    graph.resize(n_verticies);
    dist.resize(n_verticies);
    vis.resize(n_verticies);
    parents.resize(n_verticies);

    reset_values();

    cout << "Enter edges and weights (they are not treated as bidirectional):\n";
    for(int i = 0; i < n_edges; i++){
        int f, t, w;        // from to weight
        cin >> f  >> t >> w;
        f--, t--;
        graph[f].push_back({t, w});
    }

    dijkstra(0);

    for(int i = 0; i < dist.size(); i++) cout << (dist[i] == INT_MAX ? -1 : dist[i]) << ' ';
    cout << '\n';
}
