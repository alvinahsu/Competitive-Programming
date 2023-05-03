/*
*  File: CF824C
*  Author: Alvin Hsu
*  Date: 05/02/2023 14:40:02
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif
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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n; string s;
		cin >> n >> s;
		vector<char> mp(26, 'X'); 
		vector<int> vis(26);
		DSU d(26);
		int tot = 0, open = 0;
		for (int i = 0; i < n; i++){
			//haven't created a mapping yet
			if (mp[s[i]-'a'] == 'X'){
				//check characters not used
				for (char c = 'a'; c <= 'z'; c++){
					if (!vis[c-'a'] && s[i] != c){
						bool can = d.merge(s[i]-'a', c-'a');
						if (can || tot == 25) {
							mp[s[i]-'a'] = c;
							vis[c-'a'] = 1;
							tot++;
							break;
						}
					}
				}
			}
			s[i] = mp[s[i]-'a'];
		}
		cout << s << '\n';
	}
	return 0;
}
