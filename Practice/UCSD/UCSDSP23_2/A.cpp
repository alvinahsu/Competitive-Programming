/*
*  File: UCSDSP23_2A
*  Author: Alvin Hsu
*  Date: 04/24/2023 18:01:48
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
	int n;
	cin >> n;
	int sum = 0;
	while(n--){
		int a;
		cin >> a;
		sum += a;
	}
	cout << sum << '\n';
	return 0;
}
