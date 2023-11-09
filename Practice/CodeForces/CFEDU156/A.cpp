/*
*  File: CFEDU156A
*  Author: Alvin Hsu
*  Date: 11/08/2023 15:07:00
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
		if (n%3==0){
			if ((n - 5 <= 0) || (n - 5 == 1) || (n - 5 == 4)){
				cout << "NO" << '\n';
			}
			else {
				cout << "YES" << '\n';
				cout << 1 << " " << 4 << " " << n - 5 << '\n';
			}
		}
		else {
			if ((n - 3 <= 0) || (n - 3 == 1) || (n - 3 == 2)){
				cout << "NO" << '\n';
			}
			else {
				cout << "YES" << '\n';
				cout << 1 << " " << 2 << " " << n - 3 << '\n';
			}
		}
	}
	return 0;
}
