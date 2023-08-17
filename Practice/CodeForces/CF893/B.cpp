/*
*  File: CF893B
*  Author: Alvin Hsu
*  Date: 08/15/2023 16:30:02
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
		int n,m,d;
		cin >> n >> m >> d;
		vector<int> s(m);
		for (int i = 0; i < m; i++){
			cin >> s[i];
		}
		vector<int>pref(m+1), post(m+1);
		pref[0] = s[0]!=1;
		for (int i = 0; i < m; i++){
			int l = i ? s[i-1]+1 : 2;
			int diff = s[i]-l;
			pref[i+1] = pref[i] + (diff / d) + 1;	
		}
		for (int i = m-1; i >= 0; i--){
			int r = i+1<m ? s[i+1]-1 : n;
			int diff = r-s[i];
			post[i] = post[i+1] + (diff / d) + 1;
		}
		int mn = pref[m] + (n - s[m-1]) / d, cnt = 0;
		//remove s[i]
		for (int i = 0; i < m; i++){
			int l = pref[i];
			int r = post[i+1];
			int sl = i-1>=0 ? s[i-1]+1 : 2;
			int sr = i+1<m ? s[i+1]-1 : n;
			int diff = sr-sl+1;
			int curr = l + r + (diff / d) + (!i && s[i]==1);
			if (curr < mn){
				mn = curr;
				cnt = 0;
			}
			cnt += mn == curr;
		}
		cout << mn << " " << cnt << '\n';
	}
	return 0;
}
