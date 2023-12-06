#include <bits/stdc++.h>
using namespace std;

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
