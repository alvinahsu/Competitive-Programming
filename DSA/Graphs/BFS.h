#include <bits/stdc++.h>
using namespace std;

int n = 1e9, INF = 1e9, s = 0;
vector<vector<pair<int,int>>>adj;
vector<vector<int>> g;  // adjacency list representation

queue<int> q;
vector<bool> used(n);
vector<int> d(n), p(n);

// O(|V| + |E|)
void bfs(){
	q.push(s);
	used[s] = true;
	p[s] = -1;
	while (!q.empty()) {
	    int v = q.front();
	    q.pop();
	    for (int u : g[v]) {
	        if (!used[u]) {
	            used[u] = true;
	            q.push(u);
	            d[u] = d[v] + 1;
	            p[u] = v;
	        }
	    }
	}
}

// 0/1 BFS
// O(|E|)
void bfs01(){
	vector<int> d(n, INF);
	d[s] = 0;
	deque<int> q;
	q.push_front(s);
	while (!q.empty()) {
	    int v = q.front();
	    q.pop_front();
	    for (auto edge : adj[v]) {
	        int u = edge.first;
	        int w = edge.second;
	        if (d[v] + w < d[u]) {
	            d[u] = d[v] + w;
	            if (w == 1)
	                q.push_back(u);
	            else
	                q.push_front(u);
	        }
	    }
	}
}
