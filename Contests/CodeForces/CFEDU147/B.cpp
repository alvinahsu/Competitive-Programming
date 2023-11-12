/*
*  File: CFEDU147B
*  Author: Alvin Hsu
*  Date: 04/20/2023 22:27:43
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
		vector<int>a(n), b(n);
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		for (int i = 0; i < n; i++){
			cin >> b[i];
		}
		int l = 0, r = n-1;
		while(l < r && a[l] == b[l]) l++;
		while(r > l && a[r] == b[r]) r--;
		while(l > 0 && b[l-1] <= b[l]) l--;
		while(r < n-1 && b[r] <= b[r+1]) r++;
		cout << l+1 << " " << r+1 << '\n';
	}
	return 0;
}