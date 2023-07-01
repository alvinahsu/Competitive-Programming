/*
*  File: CFEDU151C
*  Author: Alvin Hsu
*  Date: 07/01/2023 14:46:01
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
		string s;
		cin >> s;
		int n;
		cin >> n;
		string l,r;
		cin >> l >> r;
		map<char,vector<int>> pos;
		for (int i = 0; i < s.size(); i++){
			pos[s[i]].push_back(i);
		}
		vector<vector<int>> lastChosen(n, vector<int>(10, -1));
		bool ok = false;
		for (int i = n-1; i >= 0; i--){
			for (char c = l[i]; c <= r[i]; c++){
				if (i == n-1){
					if (pos[c].size()){
						lastChosen[i][c-'0'] = pos[c].back();
					}
					else {
						ok = true;
					}
				}
				else {
					for (char j = '0'; j <= '9'; j++){
						if (lastChosen[i+1][j-'0'] != -1){
							while(pos[c].size() && pos[c].back() >= lastChosen[i+1][j-'0']) pos[c].pop_back();
							if (pos[c].size()){
								lastChosen[i][c-'0'] = pos[c].back();
							}
							else {
								ok = true;
							}
						}
					}
				}
			}
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}
