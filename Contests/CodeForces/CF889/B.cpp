/*
*  File: CF889B
*  Author: Alvin Hsu
*  Date: 07/29/2023 09:42:17
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
		long long n;
		cin >> n;
		int i = 1;
		while(n%(i+1)==0) i++;
		cout << i << '\n';
		
	}
	return 0;
}
