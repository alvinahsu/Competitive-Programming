/*
*  File: UCSDSP23_1C
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
	int n,x;
	cin >> n >> x;
	vector<int>v(n);
	set<int> av;
	for (auto &a : v){
		cin >> a;
		av.insert(a);
	}
	bool ok = false;
	for (int i = 0; i < n; i++){
		int find = v[i] - x;
		if (av.find(find) != av.end()){
			ok = true;
		}
		find = x + v[i];
		if (av.find(find) != av.end()){
			ok = true;
		}
	}
	cout << (ok ? "Yes" : "No") << '\n';
	return 0;
}
