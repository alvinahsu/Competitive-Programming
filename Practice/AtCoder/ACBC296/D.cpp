/*
*  File: ACBC296D
*  Author: Alvin Hsu
*  Date: 04/04/2023 18:37:10
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
	
	long long n,m;
	cin >> n >> m;
	//[1 : N*N]
	//n*n < m n < sqrt(m)
	if (n < ceil(sqrt(m))){
		cout << -1 << '\n';
		return 0;
	}
	if (m%2==0){
		cout << m << '\n';
	}
	else {
		cout << m+1 << '\n';
	}
	
	return 0;	
}
