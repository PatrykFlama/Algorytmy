#include <bits/stdc++.h>
using namespace std;

const int L = 1e5+5;
vector<int> graph[L];
bool visited[L];


void dfs(int node){
	visited[node] = true;

	for(int neighbour : graph[node]){
		if(!visited[neighbour]){
			dfs(neighbour);
		}
	}
}


int main(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int from, to; cin >> from >> to;
		graph(from).push_back(to);
		graph(to).push_back(from);
	}

	dfs(0);

	return 0;
}