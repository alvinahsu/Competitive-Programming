	#include <bits/stdc++.h>
using namespace std;

vector<bool>isPrime;
vector<int> sieve(int lim) {
	isPrime.assign(lim,1);
	isPrime[0] = isPrime[1] = 0;
	for (int i = 4; i < lim; i += 2) isPrime[i] = 0;
	for (int i = 3; i*i < lim; i += 2) 
		if (isPrime[i]) {
			for (int j = i*i; j < lim; j += i*2) isPrime[j] = 0;
		}
	vector<int> pr;
	for (int i = 2; i < lim; i++) {
		if (isPrime[i]) pr.push_back(i);
	}
	return pr;
}

const int N = 0;
bool prime[N];
void sieve(){
	for (int i = 2; i <= N; i++) {
	    if (prime[i] && 1ll * i * i <= N) {
	        for (int j = i * i; j <= N; j += i) {
	            prime[j] = false;
	        }
	    }
	}
}