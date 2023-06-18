/*
*  File: CF880C
*  Author: Alvin Hsu
*  Date: 06/18/2023 10:25:10
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif


long long p(auto a, auto b){
	long long ans = 1;
	while(b){
		if (b&1) ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		long long a,b,c,k;
		cin >> a >> b >> c >> k;
		a--, b--, c--;
		long long start = p(10, a);
		long long endStart = p(10, a+1);
		long long mxC = p(10, c+1) - 1;
		long long mnC = p(10, c);
		for (int i = start; i < endStart; i++){
			//see how many b's we can use
			long long lb = max(p(10,b),mnC - i);
			long long up = mxC - i;
			if (up < 0){
				continue;
			}
			
			//check if lower bound is valid 
			if (to_string(lb).size() > b+1) {
				assert(to_string(up).size() > b+1);
				continue;
			}
			//update the upper bound
			if (to_string(up).size() > b+1){
				up = p(10, b+1) - 1;
			}			
			if (lb > up) continue;
			long long take = min(k, up - lb + 1);
			k -= take;
			if (!k){
				cout << i << " + " << lb + take - 1 << " = " << i + lb + take - 1 << '\n';
				break;
			}
			
		}
		if (k){
			cout << -1 << '\n';
		}
		
	}
	return 0;
}
