//! LCA
//? https://themis.ii.uni.wroc.pl/2021IIAGIMROZ/RNO_LCA
#include<bits/stdc++.h>
using namespace std;
#define foo(val, from, to) for(int val = from; val < to; val++)

const int L = 2e5+5, LG = 18;
vector<int> tree[L];
int fathers[L];
pair<int, int> pp[L];
int jumps[L][LG];
int t = 1;


void dfs(int u){
    pp[u].first = t++;

    jumps[u][0] = fathers[u];
    foo(i, 1, LG)
        jumps[u][i] = jumps[jumps[u][i-1]][i-1];

    for(int i : tree[u])
        if(i != fathers[u])
            dfs(i);

    pp[u].second = t++;
}

bool in_stree(int u, int v){
    return (pp[u].first <= pp[v].first) && (pp[u].second >= pp[v].second);
}

int lca(int u, int v){
    if(in_stree(u, v))
        return u;
    if(in_stree(v, u))
        return v;
    for(int i = LG-1; i >= 0; i--){
        if(!in_stree(jumps[u][i], v))
            u = jumps[u][i];
    }
    return jumps[u][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    fathers[1] = 1, tree[1].push_back(1);
    foo(i, 2, n+1){
        cin >> fathers[i];
        tree[fathers[i]].push_back(i);
    }

    dfs(1);

    cin >> t;
    while(t--){
        int u, v; cin >> u >> v;
        cout << lca(u, v) << '\n';
    }

    return 0;
}