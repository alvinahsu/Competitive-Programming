/*
*  File: CFCodeTonR7D
*  Author: Alvin Hsu
*  Date: 11/25/2023 06:28:12
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
		int n,q;
		cin >> n >> q;
		vector<int> a(n);
		int sum = 0;
		set<int> idx;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			if (a[i] == 1) idx.insert(i);
			sum += a[i];
		}
		
		auto solve = [&](int s){
			if (sum < s) return false;
			else if ((sum&1) == (s&1)) return true;
			else if (idx.empty()) return false;
			
			//different parity
			int l = *idx.begin();
			int r = *idx.rbegin();
			
			if (sum - 2 * l > s) return true;
			if (sum - 2 * (n - r - 1) > s) return true;
			return false;
		};
		
		while(q--){
			int op;
			cin >> op;
			if (op == 1){
				int s;
				cin >> s;
				cout << (solve(s) ? "YES" : "NO") << '\n';
			}
			else {
				int i,v;
				cin >> i >> v;
				i--;
				sum -= a[i];
				if (a[i] == 1) idx.erase(i); 
				a[i] = v;
				if (v == 1) idx.insert(i);				
				sum += a[i];
				
			}
		}
	}
	return 0;
}
