/*
*  File: CFEDU146C
*  Author: Alvin Hsu
*  Date: 06/04/2023 22:28:44
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
		int n,s1,s2;
		cin >> n >> s1 >> s2;
		vector<pair<int,int>>v(n);
		for (int i = 0; i < n; i++){
			int a;
			cin >> a;
			v[i] = {a, i+1};
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		vector<int> ans1, ans2;
		for (int i = 0; i < n; i++){
			int sz1 = ans1.size();
			int sz2 = ans2.size();
			
			int place1 = (sz1+1) * s1;
			int place2 = (sz2+1) * s2;
			if (place1 <= place2){
				ans1.push_back(v[i].second);
			}
			else {
				ans2.push_back(v[i].second);
			}
		}
		cout << ans1.size() << ' ';
		for (auto &a : ans1){
			cout << a << " ";
		}
		cout << '\n';
		cout << ans2.size() << ' ';
		for (auto &a : ans2){
			cout << a << " ";
		}
		cout << '\n';
	}
	return 0;	
}
