/*
*  File: CF888F
*  Author: Alvin Hsu
*  Date: 07/25/2023 10:28:24
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
		vector<pair<int,int>> v(n);
		for (int i = 0; i < n; i++){
			cin >> v[i].first;
			v[i].second = i;
		}
		sort(v.begin(), v.end());
		pair<int,int> ans = {0,1};
		int x = 0;
		int mx = 0;
		for (int i = 0; i+1 < n; i++){
			int tryX = 0;
			for (int j = 0; j < k; j++){
				if (!(v[i].first&(1<<j)) && !(v[i+1].first&(1<<j))){
					tryX ^= (1 << j);
				}
			}
			int currMx = (tryX^v[i].first) & (tryX^v[i+1].first);
			if (currMx > mx){
				ans = {v[i].second,v[i+1].second};
				mx = currMx;
				x = tryX;
			}
		}
		cout << ans.first+1 << " " << ans.second+1 << " " << x << '\n';
	}
	return 0;
}
