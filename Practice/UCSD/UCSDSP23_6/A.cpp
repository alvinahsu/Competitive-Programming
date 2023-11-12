/*
*  File: UCSDSP23_6A
*  Author: Alvin Hsu
*  Date: 05/22/2023 18:10:15
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
		deque<int> N, B;
		for (int i = 0; i < n; i++){
			B.push_back(3*i+1);
			N.push_back(3*i+3);
		}
		vector<pair<int,int>> ans;
		while(B.size() && B.front() < N.back()){
			ans.emplace_back(B.front(), N.back());
			B.pop_front(); N.pop_back();
		}
		cout << ans.size() << '\n';
		for (auto &a : ans){
			cout << a.first << " " << a.second << '\n';
		}
	}
	return 0;
}
