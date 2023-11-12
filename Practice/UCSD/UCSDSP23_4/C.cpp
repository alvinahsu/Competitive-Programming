/*
*  File: UCSDSP23_4C
*  Author: Alvin Hsu
*  Date: 05/08/2023 20:22:09
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
	int n,k;
	cin >> n >> k;
	vector<int>v(k);
	for (auto &a : v){
		cin >> a;
		a--;
	}
	vector<pair<int,int>> vp(n);
	for (auto &a : vp){
		cin >> a.first >> a.second;
	}
	auto check = [&](double r){
		vector<int> vis(n);
		for (auto &a : v){
			vis[a] = 1;
			auto [x,y] = vp[a];
			for (int i = 0; i < n; i++){
				auto [x1,y1] = vp[i];
				long double dist = sqrt(1ll*(x-x1)*(x-x1) + 1ll*(y-y1)*(y-y1));
				vis[i] |= dist <= r; 
			}
		}
		return count(vis.begin(), vis.end(), 0) == 0;
	};
	long long l = 0, r = 1e12;
	while(l < r){
		long long d = l + (r - l) / 2;
		long double R = sqrt(d);
		if (check(R)){
			r = d;
		}
		else {
			l = d+1;
		}
	}
	cout << setprecision(15) << sqrt(l) << '\n';
	return 0;
}
