/*
*  File: CF867E
*  Author: Alvin Hsu
*  Date: 04/24/2023 08:12:23
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
		int n;
		string s;
		cin >> n >> s;
		if (n&1){
			cout << -1 << '\n';
			continue;
		}
		int v = 0;
		map<char,int> cnt;
		bool ok = true;
		for (int i = 0; i < n; i++){
			cnt[s[i]]++;
			if (cnt[s[i]] > (n / 2)) {
				ok = false;
			}
		}
		if (!ok){
			cout << -1 << '\n';
			continue;
		}
		cnt.clear();
		for (int i = 0; i < n-i-1; i++){
			if (s[i] == s[n-i-1]){
				cnt[s[i]]++;
			}
		}
		int mx = 0, sum = 0;
		for (auto &a : cnt){
			mx = max(mx, a.second);
			sum += a.second;
		}
		cout << max(mx, (sum+1)/2) << '\n';
	}
	return 0;
}