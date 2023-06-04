/*
*  File: CF877B
*  Author: Alvin Hsu
*  Date: 06/04/2023 10:10:51
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
	//at most n subarrays
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>v(n+1), pos(n+1);
		for (int i = 1; i <= n; i++){
			cin >> v[i];
			pos[v[i]] = i;
		}
		if (pos[1] == 1){
			cout << 2 << " " << pos[n] << '\n';
		}
		else if (pos[1] == n){
			cout << n-1 << " " << pos[n] << '\n';
		}
		else {
			if (pos[n] > pos[2] && pos[2] > pos[1]){
				cout << pos[2] << " " << pos[n] << '\n';
			}
			else if (pos[n] < pos[2] && pos[2] < pos[1]){
				cout << pos[2] << " " << pos[n] << '\n';
			}
			else {
				if ((pos[n] > pos[2] && pos[n] < pos[1]) || 
					(pos[n] < pos[2] && pos[n] > pos[1])){
					cout << 1 << " " << 1 << '\n';
				}
				else {
					cout << pos[1] << " " << pos[n] << '\n';
				}
			}
		}
		
	}
	return 0;
}
