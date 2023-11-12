/*
*  File: CF890E1
*  Author: Alvin Hsu
*  Date: 08/06/2023 11:14:32
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

const int N = 5005;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> g(n+1), mx(n+1);
	vector<int> sz(n+1);
	
	
	for (int i = 2; i <= n; i++){
		int p;
		cin >> p;
		g[p].push_back(i);
	}
	long long ans = 0;
	//partition into 2 sets such that the difference is minimized
	auto getBest = [&](vector<int> tree) -> long long{
		long long best = 0;
		bitset<N> bs;
		bs[0] = 1;
		//enumerate all possible sets (knapsack)
		for (auto &a : tree){
			bs |= (bs << a);
		}
		long long sum = accumulate(tree.begin(), tree.end(), 0ll);
		for (int i = 0; i < N; i++){
			if (bs[i]){
				best = max(best, i * (sum - i));
			}
		}
		return best;
	};
	function<void(int)> dfs = [&](int u){
		sz[u] = 1;
		for (auto &v : g[u]){
			dfs(v);
			sz[u] += sz[v];
			mx[u].push_back(sz[v]);
		}
		ans += getBest(mx[u]);
	};
	dfs(1);
	cout << ans << '\n';
	return 0;
}
