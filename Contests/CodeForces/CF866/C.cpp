/*
*  File: CF866C
*  Author: Alvin Hsu
*  Date: 15/04/2023 17:01:56
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
		vector<int>v(n);
		set<int> s;
		map<int,int> cnt;
		map<int, vector<int>>idx;
		for (int i = 0; i < n; i++){
			cin >> v[i];
			s.insert(v[i]);
			idx[v[i]].push_back(i);
			cnt[v[i]]++;
		}
		int mex = 0;
		for (auto &a : s){
			if (a != mex) break;
			mex++;
		}
		//no open space
		if (mex == n){
			cout << "NO" << '\n';
			continue;	
		}
		int rem = mex+1;
		//can just use any element greater than mex
		if (idx[rem].empty()){
			cout << "YES" << '\n';
			continue;
		}
		int lower = idx[rem].front(), upper = idx[rem].back();
		bool ok = true;
		for (int i = lower; i <= upper; i++){
			cnt[v[i]]--;
			if (v[i] < mex && cnt[v[i]] <= 0) {
				ok = false;
			}
		}
		cout << (ok ? "YES" : "NO") << '\n';
		
	}
	return 0;
}
