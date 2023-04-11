/*
*  File: UCSDSP23_0B
*  Author: Alvin Hsu
*  Date: 11/04/2023 09:24:55
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
	int n,m;
	cin >> n >> m;
	//(i-1)x7 + j
	vector<vector<int>>v(n, vector<int>(m));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> v[i][j];
			v[i][j]--;
		}
	}
	//right % 6
	//left % 7
	bool ok = v[0][0]%7+m <= 7;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (j) {
				ok &= (v[i][j] - v[i][j-1] == 1);
			}
			if (i) {
				ok &= (v[i][j] - v[i-1][j] == 7);
			}
		}
	}
	cout << (ok ? "Yes" : "No") << '\n';
	return 0;	
}
