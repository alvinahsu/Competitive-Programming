/*
*  File: CF892A
*  Author: Alvin Hsu
*  Date: 08/14/2023 16:36:22
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
		vector<int> a(n),b,c;
		bool ok = true;
		for (auto &i : a){
			cin >> i;
		}
		sort(a.rbegin(), a.rend());
		int i = 0;
		c.push_back(a[i++]);
		while(i < n && a[i] == c.back()){
			c.push_back(a[i++]);
		}
		while(i < n){
			b.push_back(a[i++]);
		}
		if (b.empty()){
			cout << -1 << '\n';
		}
		else {
			cout << b.size() << " " << c.size() << '\n';
			for (auto &it : b){
				cout << it << ' ';
			}
			cout << '\n';
			for (auto &it : c){
				cout << it << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}
