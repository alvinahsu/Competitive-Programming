/*
*  File: CFEDU159E
*  Author: Alvin Hsu
*  Date: 12/04/2023 13:44:28
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

struct Trie {
    int id = 0;
    vector<vector<int>> t;
    vector<int> f;
    
    Trie(int M = 1000100, int A = 26){
    	t = vector<vector<int>>(M, vector<int>(A));
    	f = vector<int>(M);
    }
 
    void add(string s) {
        int x = 0;
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            if (!t[x][c]) {
                t[x][c] = ++id;
            }
            x = t[x][c];
            f[x] += 1;
        }
    }
 
    long long get(string s) {
        int x = 0;
        long long res = 0;
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
 
            if (!t[x][c]) {
                break;
            }
 
            x = t[x][c];
            res += f[x];
        }
        return res;
    }
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<string> v(n);
	Trie T;
	long long a = 0, b = 0;
	for (int i = 0; i < n; i++){
		cin >> v[i];
		T.add(v[i]);
		a += v[i].size();
	}
	
	for (int i = 0; i < n; i++){
		reverse(v[i].begin(), v[i].end());
		b += T.get(v[i]);
	}
	cout << 2*(a*n-b) << '\n';
	return 0;
}
