/*
*  File: CF900A
*  Author: Alvin Hsu
*  Date: 09/26/2023 07:25:15
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
		vector<int> v(n);
		for (auto &it : v){
			cin >> it;
		}
		if (count(v.begin(), v.end(), k)){
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
		
	}
	return 0;
}
