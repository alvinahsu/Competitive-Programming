/*
*  File: CF910E
*  Author: Alvin Hsu
*  Date: 11/19/2023 06:28:26
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
    int tt;
    cin >> tt;
    while(tt--){
    	int n,m;
    	cin >> n >> m;
    	string s,t;
    	cin >> s >> t;
    	bool ok = true;
    	vector<vector<int>> idx(26);
    	vector<int> upd(n);
    	for (int i = 0; i < n; i++){
    		idx[s[i]-'a'].push_back(i);
    	}
    	for (int i = 0; i < 26; i++){
    		reverse(idx[i].begin(), idx[i].end());
    	}
    	for (int i = 0; i < m; i++){
    		if (idx[t[i]-'a'].empty()){
    			ok = false;
    			break;
    		}
    		int dj = idx[t[i]-'a'].back(); idx[t[i]-'a'].pop_back();
    		for (int k = 0; k < t[i]-'a'; k++){
    			while(idx[k].size() && idx[k].back() < dj){
    				idx[k].pop_back();
    			}
    		}    		
    	}
    	cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}