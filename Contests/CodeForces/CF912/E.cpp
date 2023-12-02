/*
*  File: CF912E
*  Author: Alvin Hsu
*  Date: 11/30/2023 11:49:50
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
		vector<int> cnt(2);
		int x,y;
		cin >> x >> y;
		for (int i = 0; i < n; i++){
			int xx,yy;
			cin >> xx >> yy;
			int p = xx%2 + yy%2;
			cnt[p%2]++;
		}
		int last = (x%2+y%2)%2;
		//cnt[i] -> cnt[i^1] to get odd
		//cnt[i] -> cnt[i] to get even
		int diff = max(cnt[0],cnt[1]) - min(cnt[0],cnt[1]);
		dbg(cnt,diff,last);
		if ((diff/2)&1){
			cout << "First" << '\n';
		}
		
	}
	return 0;
}
