/*
*  File: CF888E
*  Author: Alvin Hsu
*  Date: 07/25/2023 10:28:24
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

const long long inf = 1e18;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		vector<int> have(n), in(n);
		vector<long long> c(n), best(n,1e18);
		vector<map<int,int>> g(n);
		
		for (auto &a : c){
			cin >> a;
		}
		for (int i = 0; i < k; i++){
			int x;
			cin >> x;
			x--;
			have[x] = 1;
		}
		for (int i = 0; i < n; i++){
			int m;
			cin >> m;
			for (int j = 0; j < m; j++){
				int x;
				cin >> x;
				x--;
				in[i]++;
				g[x][i]++;
			}
		}
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> s;
		for (int i = 0; i < n; i++){
			if (!in[i]){
				if (!have[i]) best[i] = c[i];
				else best[i] = 0;
				s.push({best[i],i});
			}
		}
		while(s.size()){
			auto [cost,curr] = s.top(); s.pop();
			if (have[curr]) best[curr] = 0;
			best[curr] = min(best[curr], c[curr]);
			for (auto &[x,y] : g[curr]){
				if (best[x] == inf) best[x] = 0;
				best[x] += (best[curr] * y);
				in[x] -= y;
				if (!in[x]) s.push({best[x],x});
			}
		}
		for (int i = 0; i < n; i++){
			cout << min(best[i], c[i]) << ' ';
		}
		cout << '\n';
	}
	return 0;
}
