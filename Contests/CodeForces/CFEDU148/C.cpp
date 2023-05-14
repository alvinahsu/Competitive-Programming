/*
*  File: CFEDU148C
*  Author: Alvin Hsu
*  Date: 05/12/2023 07:33:53
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
		for (int i = 0; i < n; i++){
			cin >> v[i];
		}
		int ans = 0;
		int j = 0;
		for (int i = 0; i < n; i++){
			ans++;
			j = i+1;
			while(j+1 < n){
				int diff = abs(v[i] - v[j]) + abs(v[j] - v[j+1]);
				if (abs(v[i] - v[j+1]) == diff){
					j++;
				}
				else {
					break;
				}
			}
			if (j < n && v[i] == v[j]) ans--;
			i = j-1;
		}
		cout << ans << '\n';
	}
	return 0;
}
