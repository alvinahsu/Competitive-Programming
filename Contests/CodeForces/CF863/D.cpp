/*
*  File: CF863D
*  Author: Alvin Hsu 
*  Date: 04/04/2023 18:36:29
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

int f[45];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	f[0] = f[1] = 1;
	for (int i = 2; i <= 44; i++) {
		f[i] = f[i-1] + f[i-2];
	}
	int t;
	cin >> t;
	while(t--){
		int n,x,y;
		cin >> n >> x >> y;
		//h(x) = f[n] = f[n-1] + f[n-2]
		//w(y)	 = f[n+1] = f[n] + f[n-1]
		bool ok = true;
		while(n){
			//right half 
			if (y > f[n]) {
				y -= f[n];
			}
			//left half
			else if (y > f[n-1]){
				ok = false;
				break;
			}
			swap(x,y);
			n--;
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;	
}
