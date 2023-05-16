/*
*  File: UCSDSP23_5D
*  Author: Alvin Hsu
*  Date: 05/15/2023 18:17:26
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
	//always need to go the absolute min
	//if multiple spots, we need to travel at least (mx - mn)
	//between mx and mn, 
	//other, go straight to mn to mx
	//solve: end at mn or mx for a number?
	long long inf = 1e18;
	int n;
	cin >> n;
	vector<int>v = {0};
	map<int, pair<int,int>> mp;
	mp[0] = {0,0};
	for (int i = 0; i < n; i++){
		int x,c;
		cin >> x >> c;
		v.push_back(c);
		if (mp.find(c) == mp.end()){
			mp[c] = {x,x};
		}
		else {
			mp[c].first = min(mp[c].first, x);
			mp[c].second = max(mp[c].second, x);
		}
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	v.push_back(0);
	vector<vector<long long>> dp(v.size(), vector<long long>(2, inf));
	auto check = [&](long long x, long long mn, long long mx){
		return abs(x - mn) + abs(mx - mn);
	};
	dp[0][0] = dp[0][1] = 0;
	for (int i = 1; i < v.size(); i++){
		long long c = v[i], fx = mp[c].first, sx = mp[c].second;
		long long p = v[i-1], pfx = mp[p].first, psx = mp[p].second;
		//p first -> fx, p first -> sx, p second -> fx, p second -> sx
		dp[i][0] = min(dp[i-1][0] + check(pfx, sx, fx), dp[i-1][1] + check(psx, sx, fx));
		dp[i][1] = min(dp[i-1][0] + check(pfx, fx, sx), dp[i-1][1] + check(psx, fx, sx));
	}
	cout << min(dp[v.size()-1][0], dp[v.size()-1][1]) << '\n';
	return 0;
}

