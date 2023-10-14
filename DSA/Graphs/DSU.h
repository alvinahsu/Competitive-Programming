#include <bits/stdc++.h>
using namespace std;

// O(n)
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
