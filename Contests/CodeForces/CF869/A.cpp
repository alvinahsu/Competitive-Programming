/*
*  File: CF869A
*  Author: Alvin Hsu
*  Date: 04/29/2023 07:30:07
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
		int ans = n;
		//always keep member 1, make it majority
		vector<vector<char>> v(n, vector<char>(k));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < k; j++){
				cin >> v[i][j];
			}
		}
		vector<int> rem(n);
		for (int i = 0; i < k; i++){
			char c = v[0][i];
			int cnt = 1;
			for (int j = 1; j < n; j++){
				if (!rem[j]) {
					if (v[j][i] == c){
						cnt++;
					}
					else {
						rem[j] = 1;
					}
				}
			}
			ans = min(ans, cnt);
		}
		cout << ans << '\n';	
	}
	return 0;
}
