/*
*  File: CF904A
*  Author: Alvin Hsu
*  Date: 10/21/2023 22:46:09
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
		int x,k;
		cin >> x >> k;
		auto check = [&](int i){
			int sum = 0;
			while(i){
				sum += i%10;
				i/=10;
			}
			return sum%k == 0;
		};
		for (int i = x; i <= x + 1e6; i++){
			if (check(i)){
				cout << i << '\n';
				break;
			}
		}
	}
	return 0;
}
