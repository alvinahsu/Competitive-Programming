/*
*  File: CF886F
*  Author: Alvin Hsu
*  Date: 07/23/2023 15:07:49
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
		cin >> n;
		vector<int>v(n);
		map<int,int> cnt;
		for (auto &a : v){
			cin >> a;
			cnt[a]++;
		}
		vector<int> ans(n+1);
		for (auto &[x,y] : cnt){
			for (int i = x; i <= n; i+=x){
				ans[i]+=y;
			}
		}
		cout << *max_element(ans.begin(), ans.end()) << '\n';
	}
	return 0;
}
