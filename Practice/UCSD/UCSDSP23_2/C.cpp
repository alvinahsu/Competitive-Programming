/*
*  File: UCSDSP23_2C
*  Author: Alvin Hsu
*  Date: 04/24/2023 18:01:48
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

using ppi = pair<int, pair<int,int>>;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	
	priority_queue<ppi, vector<ppi>, greater<>> pq;
	pq.push({0, {1,1}});
	vector<vector<int>> dist(n+1, vector<int>(n+1, 1e8));
	while(pq.size()){
		auto top = pq.top(); pq.pop();
		auto d = top.first;
		auto i = top.second.first, j = top.second.second;
		dist[i][j] = d;
		
		
	}
	return 0;
}
