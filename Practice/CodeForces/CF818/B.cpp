/*
*  File: CF818B
*  Author: Alvin Hsu
*  Date: 04/28/2023 08:06:22
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
		int n,k,r,c;
		cin >> n >> k >> r >> c;
		vector<vector<char>> v(n, vector<char>(n, '.'));
		r--, c--;
		
		auto mark = [&](int i, int j){
			i -= 2 * n;
			j -= 2 * n;
			for (int k = 0; k < 4*n; k++){
				if (i >= 0 && i < n && j >= 0 && j < n){
					v[i][j] = 'X';
				}
				i++;
				j++;
			}
		};
		c -= 2 * n;
		for (int i = 0; i < 4*n; i++){
			mark(r, c);
			c += k;
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cout << v[i][j];
			}
			cout << '\n';
		}
	}
	return 0;
}
