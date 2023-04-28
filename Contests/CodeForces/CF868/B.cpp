/*
*  File: CF868B
*  Author: Alvin Hsu
*  Date: 04/27/2023 07:17:17
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
		int n,k;
		cin >> n >> k;
		vector<int>v(n);
		for (auto &a : v){
			cin >> a;
		}
		vector<int> srt = v;
		sort(srt.begin(), srt.end());
		vector<int> vis(n);
		int cnt = 0;
		for (int i = 0; i < n; i++){
			if (!vis[i]){
				set<int> s, cmp;
				for (int j = i; j < n; j+=k){
					s.insert(v[j]);
					cmp.insert(srt[j]);
					vis[j] = 1;
				}
				for (auto &a : s){
					if (cmp.find(a) == cmp.end()) cnt++;
				}
			}
		}
		if (cnt == 0){
			cout << 0 << '\n';
		}
		else if (cnt == 2){
			cout << 1 << '\n';
		}
		else {
			cout << -1 << '\n';
		}
	}
	return 0;
}
