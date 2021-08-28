#include <bits/stdc++.h>
using namespace std;

const int L = 1e5+5;
vector<int> graph[L];
visited[L];


void bfs(int node){
	queue<int> q;
	q.push_back(node);
	visited[node] = true;

	while(!q.empty()){
		node = q.front();
		q.pop_front();

		for(int neighbour : graph[node]){
			if(!visited[neighbour]){
				q.push_back(neighbour);
			}
		}
	}
}


int main(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int from, to; cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	bfs(0);

	return 0;
}