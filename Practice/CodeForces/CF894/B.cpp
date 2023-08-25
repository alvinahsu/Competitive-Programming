/*
*  File: CF894B
*  Author: Alvin Hsu
*  Date: 08/24/2023 13:32:25
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
		vector<int> b(n);
		for (int i = 0; i < n; i++){
			cin >> b[i]; 
		}
		vector<int> ans;
		ans.push_back(b[0]);
		for (int i = 1; i < n; i++){
			if (b[i] >= ans.back()) ans.push_back(b[i]);
			else {
				ans.push_back(b[i]);
				ans.push_back(b[i]);
			}
		}
		cout << ans.size() << '\n';
		for (auto &a : ans){
			cout << a << " ";
		}
		cout << '\n';
	}
	return 0;
}
