/*
*  File: CF908D
*  Author: Alvin Hsu
*  Date: 11/07/2023 06:28:00
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
		int n,m;
		cin >> n >> m;
		map<int,int> cnt;
		vector<int> a(n), b(m);
		for (auto &it : a){
			cin >> it;
		}
		for (auto &it : b){
			cin >> it;
		}
		sort(b.rbegin(), b.rend());
		vector<int> c(n+m);
		int l = 0, p = 0;
		for (int i = 0; i < n; i++){
			while(p < m && b[p] >= a[i]) c[l++] = b[p++];
			c[l++] = a[i];
		}
		while(p < m){
			c[l++] = b[p++];
		}
		for (int i = 0; i < n + m; i++){
			cout << c[i] << " \n"[i == n + m -	1];
		}
	}
	
	
	return 0;
}