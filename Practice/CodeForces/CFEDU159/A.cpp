/*
*  File: CFEDU159A
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
		if (cnt0 && cnt1){
			cout << "YES" << '\n';
		}
		else if (cnt0 > cnt1){
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
	return 0;
}
