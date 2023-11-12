/*
*  File: AC297C
*  Author: Alvin Hsu
*  Date: 11/04/2023 09:03:51
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
	int h,w;
	cin >> h >> w;
	vector<string> v(h);
	for (auto &a : v){
		cin >> a;
	}
	for (int i = 0; i < h; i++){
		for (int j = 0; j < w-1; j++){
			if (v[i][j] == 'T' && v[i][j+1] == 'T') {
				v[i][j] = 'P';
				v[i][j+1] = 'C';
			}
		}
	}
	for (auto &a : v){
		cout << a << '\n';
	}
	return 0;	
}
