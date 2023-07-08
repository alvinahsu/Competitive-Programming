/*
*  File: CF883E
*  Author: Alvin Hsu
*  Date: 07/07/2023 10:32:34
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

long long fastpow(long long a, long long b){
	long long res = 1;
	while(b){
		if (b&1) res *= a;
		a *= a;
		if (a * a / a != a) return -1;
		b >>= 1;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	map<long long, vector<int>> mp;
	vector<int> ans(t);
	for (int i = 0; i < t; i++){
		long long n;
		cin >> n;
		//limited to only 1 + k + k^2
		if (n > 1e5){
			long long l = 1e5, r = 1e9;
			while(l < r){
				long long m = l + (r - l + 1) / 2;
				long long have = 1 + m + m * m;
				if (have > n) r = m-1;
				else l = m;
			}
			long long have = 1 + l + l * l;
			if (have == n) ans[i] = 1;
		}
		mp[n].push_back(i);
	}
	
	//brute force 1 + k + k^2 ... + k^n
	for (int i = 2; i <= 1e6; i++){
		for (int j = 2; j <= 80; j++){
			long long check = fastpow(i, j+1) - 1;
			if (check == -1) break;
			if (check%(i-1) != 0) continue;
			long long have = check / (i-1);
			while(mp[have].size()){
				ans[mp[have].back()] = 1;
				mp[have].pop_back();
			}
		}
	}
	for (int i = 0; i < t; i++){
		cout << (ans[i] ? "YES" : "NO") << '\n';
	}
	
	return 0;
}
