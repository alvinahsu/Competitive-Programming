#include <bits/stdc++.h>
using namespace std;

long long power(long long a, long long m){
	long long ans = 1, b = m-2;
	while(b){
		if (b&1) {
			(ans *= a) %= m;
		}
		b >>= 1;
		(a *= a) %= m;
	}
	return ans;
}

long long inv(long long a, long long m){
	if (gcd(a,m) != 1) {
		return -1;
	}
	return power(a, m);
}


// long long inv(long long a, long long b){
//  return (a > 1) ? b - inv(b%a,a)*b/a : 1;
// }

/*
Computing from [1,m-1] in O(n)
inv[1] = 1;
for(int i = 2; i < m; ++i)
    inv[i] = m - (long long)(m/i) * inv[m%i] % m;
*/