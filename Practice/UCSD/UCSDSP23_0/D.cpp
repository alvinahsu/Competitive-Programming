/*
*  File: UCSDSP23_0D
*  Author: Alvin Hsu
*  Date: 11/04/2023 09:24:55
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
	int n;
	cin >> n;
	vector<int>v;
	vector<pair<int,int>> seg;
	int curr = -1, cnt = 0;
	int tot = 0;
	while(n--){
		int a;
		cin >> a;
		tot++;
		if (a != curr){
			seg.push_back({curr, cnt});
			curr = a;
			cnt = 1;
		}
		else {
			cnt++;
			if (a >= 2 && cnt == a){
				tot -= cnt;
				if (seg.size()){
					auto prev = seg.back();
					curr = prev.first, cnt = prev.second;
					seg.pop_back();
				}
				else {
					curr = -1, cnt = 0;
				}
			}
		}
		cout << tot << '\n';
	}
	return 0;	
}
