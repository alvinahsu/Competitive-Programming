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
		if (pos[n] < min(pos[1], pos[2])){
			cout << min(pos[1], pos[2])  << " " << pos[n] << '\n';
		}
		else if (pos[n] > max(pos[1], pos[2])){
			cout << max(pos[1], pos[2]) <<  " " << pos[n] << '\n';
		}
		else {
			cout << "1 1" << '\n';
		}
	}
	return 0;
}
