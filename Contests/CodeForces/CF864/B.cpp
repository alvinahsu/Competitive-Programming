/*
*  File: CF864B
*  Author: Alvin Hsu
*  Date: 08/04/2023 21:59:37
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
		vector<vector<int>>v(n, vector<int>(n));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cin >> v[i][j];
			}
		}
		auto rIndex = [&](int i, int j){
			int newI = n - i - 1;
			int newJ = n - j - 1;
			return make_pair(newI, newJ);
		};
		bool ok = true;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				auto newIdx = rIndex(i,j);
				int newI = newIdx.first;
				int newJ = newIdx.second;
				if (v[newI][newJ] == v[i][j]) continue;
				else {
					k--;
					v[newI][newJ] ^= 1;
					
					if (k < 0) ok = false;
				}
			}
		}
		ok &= (k%2==0 || (k&1 && n&1));
		dbg(k);
		cout << (ok ? "YES" : "NO") << '\n';
		
	}
	return 0;
}
