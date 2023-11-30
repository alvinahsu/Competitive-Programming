/*
*  File: CFEDU158C
*  Author: Alvin Hsu
*  Date: 11/28/2023 20:12:02
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
		vector<int> v(n);
		for (int i = 0; i < n; i++){
			cin >> v[i];
		}
		int mn = *min_element(v.begin(), v.end());
		int mx = *max_element(v.begin(), v.end());
		vector<int> res;
		while(mn != mx){
			res.push_back(mn&1);
			mn = (mn + res.back()) / 2;
			mx = (mx + res.back()) / 2;
		}
		cout << res.size() << '\n';
		if (res.size() <= n){
			for (int i = 0; i < res.size(); i++){
				cout << res[i] << " \n"[i == res.size()-1];
			}
		}
	}
	return 0;
}
