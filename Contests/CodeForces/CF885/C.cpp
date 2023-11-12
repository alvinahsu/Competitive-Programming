/*
*  File: CF885C
*  Author: Alvin Hsu
*  Date: 07/16/2023 10:04:19
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

int dfs(int a,int b){
	if (a == 0) return 0;
	if (b >= 2 * a){
		int m = b / (2 * a);
		return 3*m + dfs(a, 1ll*b-2*m*a);
	}
	return 1 + dfs(b, abs(b - a));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		for (int i = 0; i < n; i++){
			cin >> b[i];
		}
        set<int> cnt;
        for (int i = 0; i < n; i++){
        	if (a[i] || b[i]){
        		//start of cycle
        		cnt.insert(dfs(a[i],b[i])%3);
        	}
        }
        if (cnt.size() <= 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
		}
	}
	return 0;
}
