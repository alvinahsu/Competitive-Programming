/*
*  File: CF910C
*  Author: Alvin Hsu
*  Date: 11/19/2023 06:28:26
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
		int n,m,k;
		cin >> n >> m >> k;
		if (n-1 + m-1 > k){
			cout << "NO" << '\n';
			continue;
		}
		k -= (n-1 + m-1);
		if (k&1){
			cout << "NO" << '\n';
		}
		else {
			assert(k%4 == 0 || k%4 == 2);
			cout << "YES" << '\n';
			for (int i = 0; i < n; i++){
				for (int j = 0; j < m-1; j++){
					cout << (j&1?'R':'B')  << " \n"[j == m-2]; 
				}
			}
			bool useR = ((m-2)&1);
			for (int i = 0; i < n-1; i++){
				for (int j = 0; j < m; j++){
					cout << ((j < m-1 && i < n-2 ? 1 : 0)^(useR^(i%2==0))?'R':'B') << " \n"[j == m-1];
				}
			}
		}
	}
	return 0;
}
