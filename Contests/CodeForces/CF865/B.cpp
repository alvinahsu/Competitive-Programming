/*
*  File: CF865B
*  Author: Alvin Hsu
*  Date: 09/04/2023 21:13:12
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
		vector<vector<int>>v(2, vector<int>(n));
		n *= 2;
		v[1][v[0].size()-1] = n--;
		int r = 0;
		for (int i = 0;i < v[0].size()-1; i++){
			v[r][i] = n--;
			r ^= 1;
		}
		r = 1;
		for (int i = 0; i < v[0].size(); i++){
			v[r][i] = n--;
			r ^= 1;
		}
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < v[0].size(); j++){
				cout << v[i][j] << " \n"[j == v[i].size()-1];
			}
		}
	}
	return 0;	
}
