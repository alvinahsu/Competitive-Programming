/*
*  File: CF824D
*  Author: Alvin Hsu
*  Date: 05/02/2023 14:40:02
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
	int n,k;
	cin >> n >> k;
	set<vector<int>> s;
	vector<vector<int>> v(n, vector<int>(k));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < k; j++){
			cin >> v[i][j];
		}
		s.insert(v[i]);
	}
	long long ans = 0;
	for (int i = 0; i < n; i++){
		int curr = 0;
		for (int j = 0; j < n; j++){
			vector<int> need(k);
			for (int l = 0; l < k; l++){
				if (v[i][l] == v[j][l]){
					need[l] = v[i][l];
				}
				else {
					int sum = v[i][l] + v[j][l];
					need[l] = 3 - sum;
				}
			}
			if (s.find(need) != s.end()){
				curr++;
			}
		}
		curr /= 2;
		ans += (curr * (curr-1) / 2);
	}
	cout << ans << '\n';
	return 0;
}
