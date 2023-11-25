/*
*  File: USACOFebSilver2021C
*  Author: Alvin Hsu
*  Date: 08/28/2023 19:22:54
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

const int inf = 1e9;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> v[i][j];
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
		}
	}
	
	return 0;
}
