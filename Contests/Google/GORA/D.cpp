/*
*  File: GORAD
*  Author: Alvin Hsu
*  Date: 15/04/2023 21:08:25
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
	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++){
		long long n;
		cin >> n;
		long long i = 1, curr = 26;
		while(curr < n){
			curr += (26 * ++i);
		}
		long long diff = curr - n;
		char c = 'Z';
		while(diff-i >= 0){
			diff -= i;
			c--;
		}
		cout << "Case #" << t << ": " << c << '\n';
	}
	return 0;
}
