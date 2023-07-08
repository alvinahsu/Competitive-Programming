/*
*  File: CF883G
*  Author: Alvin Hsu
*  Date: 07/07/2023 12:46:23
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		map<string,int> dist;
		cin >> n >> m;
		string s;
		cin >> s;
		vector<pair<int,pair<string,string>>> med(m);
		for (auto &a : med){
			cin >> a.first >> a.second.first >> a.second.second;
		}
		priority_queue<pair<long long,string>, vector<pair<long long,string>>, greater<>> q;
		q.push({0,s});
		dist[s] = 0;
		while(q.size()){
			auto [currCost, top] = q.top(); q.pop();
			for (auto &[cost,str] : med){
				string rem = str.first, add = str.second;
				string res = top;
				for (int i = 0; i < n; i++){
					if (rem[i] == '1') res[i] = '0';
					if (add[i] == '1') res[i] = '1';
				}
				if (dist.find(res) == dist.end()) {
					dist[res] = currCost + cost;
					q.push({dist[res],res});
				}
				else if (currCost + cost < dist[res]){
					dist[res] = currCost + cost;
					q.push({dist[res], res});
				}
			}
		}
		string want(n, '0');
		int ans = dist.find(want) == dist.end() ? -1 : dist[want];
		cout << ans << '\n';
	}
	return 0;
}
