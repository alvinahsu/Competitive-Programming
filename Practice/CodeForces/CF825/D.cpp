/*
*  File: CF825D
*  Author: Alvin Hsu
*  Date: 06/04/2023 16:11:26
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
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int cnt0 = count(s.begin(), s.end(), '0');
		int cnt1 = count(s.begin(), s.end(), '1');
		if (cnt0&1 || cnt1&1){
			cout << -1 << '\n';
			continue;
		}
		int need = 0;
		vector<int> ans;
		for (int i = 0; i < 2*n; i+=2){
			if (s[i] != s[i+1]){
				if (s[i]-'0' == need){
					ans.push_back(i);
				}
				else {
					ans.push_back(i+1);
				}
				need ^= 1;
			}
		}
		cout << ans.size() << " ";
		for (int i = 0; i < ans.size(); i++){
			cout << ans[i]+1 << " ";
		}
		cout << '\n';
		for (int i = 2; i <= 2*n ;i+=2){
			cout << i << " \n"[i == 2*n];
		}
	}
	return 0;	
}
