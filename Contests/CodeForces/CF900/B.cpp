/*
*  File: CF900B
*  Author: Alvin Hsu
*  Date: 09/26/2023 07:25:15
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
		int curr = 3;
		for (int i = 0; i < n; i++){
			cout << curr << " \n"[i == n-1];
			if (i%2==0) curr++;
			else curr += 2;
		}
	}
	return 0;
}
