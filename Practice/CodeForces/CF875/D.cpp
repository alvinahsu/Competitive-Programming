/*
*  File: CF875D
*  Author: Alvin Hsu
*  Date: 05/29/2023 14:02:52
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
		vector<int>a(n), b(n);
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		for (int i = 0; i < n; i++){
			cin >> b[i];
		}
		int UP = *max_element(b.begin(), b.end()) * 2 + 1;
		int SUP = sqrt(UP) + 5;
		vector<map<int,int>> cnt(2e5+5);
		
		int ans = 0;
		for (int i = 0; i < n; i++){
			for (int j = 1; j < SUP; j++){
				int get = a[i] * j - b[i];
				ans += cnt[j][get];
			}
			cnt[a[i]][b[i]]++;
		}
		cout << ans << '\n';
	}
	return 0;
}