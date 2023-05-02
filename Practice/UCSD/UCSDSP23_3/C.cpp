/*
*  File: UCSDSP23_3C
*  Author: Alvin Hsu
*  Date: 05/01/2023 17:58:30
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
	long long k;
	cin >> k;
	long long mx = 0;
	for (int i = 2; i <= 1e6; i++){
		long long curr = i, cnt = 1;
		while(k%i == 0){
			if (curr % i != 0){
				cnt++;
				curr = cnt * i;	
			}
			curr /= i;
			k /= i;
			mx = max(mx, cnt * i);
		}
	}
	cout << (!mx ? k : max(mx, k)) << '\n';
	return 0;
}
