/*
*  File: CF874E
*  Author: Alvin Hsu
*  Date: 05/19/2023 07:31:18
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

struct DSU {
	vector<int> p, s, e;
	DSU(int size) : p(size), s(size, 1) , e(size){ 
		iota(p.begin(), p.end(), 0); 
	}
	int find(int n) { 
		return p[n] == n ? n : (p[n] = find(p[n])); 
	}
	bool merge(int n1, int n2) {
		n1 = find(n1), n2 = find(n2); 
		if (n1 == n2) { 
			return false; 
		}
		if (s[n1] > s[n2]) swap(n1, n2); 
		s[n1] += s[n2], p[n2] = n1;
		e[n1] += e[n2];
		return true;
	}
	bool sameSet(int n1, int n2){ 
		return find(n1) == find(n2); 
	}	
	int getSize(int n){ 
		return s[find(n)]; 
	}
	int getEdges(int n){
		return e[find(n)];
	}
	void addEdge(int n){
		e[find(n)]++;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		DSU d(n+1);
		int comp = n;
		int closed = 0;
		vector<int>v(n+1), added(n+1);
		for (int i = 1; i <= n; i++){
			cin >> v[i];
		}
		int free = n;
		for (int i = 1; i <= n; i++){
			int u = v[i];
			if (d.merge(i,u)) {
				comp--;
			}
			if (!added[i]) {
				d.addEdge(i);
				added[i] = 1;
				if (v[u] == i) added[u] = 1;
			}
			// dbg(d.getEdges(i), i);
			if (d.getEdges(i) == d.getSize(i)){
				free -= d.getSize(i);
				closed++;
			}
		}
		cout << closed+(free>0) << " " << comp << '\n';
		
	}
	return 0;
}
