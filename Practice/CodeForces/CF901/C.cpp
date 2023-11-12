/*
*  File: CF901C
*  Author: Alvin Hsu
*  Date: 11/11/2023 15:53:38
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
		b >>= 1;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	#define int long long
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		int ans = 0;
		for (int i = 0; i <= 60; i++){
			//how many of 2^-1 can we fit
			int fit = n / m;
			n -= fit * m;
			if (!n) break;
			ans += n;
			if (LLONG_MAX / n < fastpow(2,i+1)) break;
			n *= 2;
		}
		cout << (!n ? ans : -1) << '\n';
	}
	return 0;
}
