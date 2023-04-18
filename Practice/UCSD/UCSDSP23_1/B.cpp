/*
*  File: UCSDSP23_1B
*  Author: Alvin Hsu
*  Date: 04/18/2023 09:15:04
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
	int n;
	cin >> n;
	string s;
	cin >> s;
	set<pair<int,int>> vis;
	int x = 0, y = 0;
	vis.insert({x,y});
	bool ok = false;
	for (int i = 0; i < n; i++){
		char c = s[i];
		if (c == 'R'){
			x++;
		}
		else if (c == 'L'){
			x--;
		}
		else if (c == 'U'){
			y++;
		}
		else {
			y--;
		}
		if (vis.find({x,y}) != vis.end()){
			ok = true;
		}
		vis.insert({x,y});
	}
	cout << (ok ? "Yes" : "No") << '\n';
	return 0;
}
