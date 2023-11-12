/*
*  File: CFEDU150B
*  Author: Alvin Hsu
*  Date: 06/12/2023 13:25:09
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
		int q;
		cin >> q;
		vector<int> v;
		bool shift = false;
		while(q--){
			int x;
			cin >> x;
			bool add = false;
			if (v.empty()){
				add = true;
			}
			else {
				if (x >= v.back()){
					if (!shift){
						add = true;
					}
					else{
						add = x <= v[0];
					}
				}
				else {
					if (x <= v[0] && !shift){
						add = true;
						shift = 1 ;
					}
				}
			}
			if (add) v.push_back(x);
			cout << (add ? '1' : '0');
		}
		cout << '\n';
	}
	return 0;
}
