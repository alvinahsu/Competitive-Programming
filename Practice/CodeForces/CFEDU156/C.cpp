/*
*  File: CFEDU156C
*  Author: Alvin Hsu
*  Date: 11/08/2023 15:07:00
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

long long getSize(long long n, long long rem){
	return n * (n+1) / 2 - ((n-rem-1) * (n - rem) / 2);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//remove i if s[i+1] < i
	int t;
	cin >> t;
	while(t--){
		string s;
		long long p;
		cin >> s >> p;
		int n = s.size();
		long long tot = 1ll * n * (n+1) / 2;
		int l = 0, r = n-1;
		while(l < r){
			int m = l + (r - l) / 2;
			long long left = 1ll * (n-m-1) * (n-m) / 2;
			long long rem = tot - left;
			if (rem >= p){
				r = m;
			}
			else {
				l = m+1;
			}
		}
		assert(getSize(n,l) >= p && getSize(n,l-1) < p);
		p -= getSize(n, l-1);
		string rem;
		for (int i = 0; i < n; i++){
			if (l && rem.size() && s[i] < rem.back()){
				while(l && rem.size() && s[i] < rem.back()){
					rem.pop_back();
					l--;
				}
				rem += s[i];
			}
			else if (l && i+1 < n && s[i+1] < s[i]){
				l--;
			}
			else {
				rem += s[i];
			}
		}
		assert(rem.size() > l);
		while(l--){
			rem.pop_back();
		}
		cout << rem[p-1];
		
	}
	return 0;
}
