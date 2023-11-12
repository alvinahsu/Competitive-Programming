/*
*  File: CF891G
*  Author: Alvin Hsu
*  Date: 08/07/2023 09:56:12
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

const int MOD = 998244353;
struct DSU {
	vector<int> p, s;
	DSU(int size) : p(size), s(size, 1) { 
		iota(p.begin(), p.end(), 0); 
	}
	int find(int n) { 
		return p[n] == n ? n : (p[n] = find(p[n])); 
	}
	bool merge(int n1, int n2) {
		n1 = find(n1), n2 = find(n2); 
		if (n1 == n2) { return false; }
		if (s[n1] > s[n2]) swap(n1, n2); 
		s[n1] += s[n2], p[n2] = n1; 
		return true;
	}
	bool sameSet(int n1, int n2){ 
		return find(n1) == find(n2); 
	}	
	int getSize(int n){ 
		return s[find(n)]; 
	}
};

long long fastpow(long long a, long long b){
	long long res = 1;
	while(b){
		if (b&1) (res *= a) %= MOD;
		b >>= 1;
		(a *= a) %= MOD;
	}
	return res % MOD;
}

struct Node {
	int u,v,w;	
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,S;
		cin >> n >> S;
		DSU d(n+1);
		vector<Node> v(n-1);
		for (auto &node : v){
			cin >> node.u >> node.v >> node.w;
		}
		sort(v.begin(), v.end(), [&](auto n1, auto n2){
			return n1.w < n2.w;	
		});
		long long ans = 1;
		for (int i = 0; i < n-1; i++){
			int s1 = d.getSize(d.find(v[i].u));
			int s2 = d.getSize(d.find(v[i].v));
			assert(!d.sameSet(v[i].u, v[i].v));
			(ans *= fastpow(S-v[i].w+1, 1ll*s1*s2-1)) %= MOD;
			d.merge(v[i].u, v[i].v);
		}
		cout << ans << '\n';
	}
	return 0;
}
