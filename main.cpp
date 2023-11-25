#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

int main(){	
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
    	int n;
    	cin >> n;
    	string s;
    	cin >> s;
    	int x = 0, y = 0;
    	map<pair<int,int>, int> cnt;
    	for (int i = 0; i < n; i++){
    		if (s[i] == 'D') x++;
    		else y++;
    		int g = gcd(x,y);
    		cnt[{x/g,y/g}]++;
    		cout << cnt[{x/g,y/g}] << " \n"[i == n-1];
    	}
    }
    return 0;
}