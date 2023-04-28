/*
*  File: CF868C
*  Author: Alvin Hsu
*  Date: 04/27/2023 07:17:17
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
		map<int,int> p;
		for (int i = 0; i < n; i++){
			int a;
			cin >> a;
			int A = a;
			for (int j = 2; j <= sqrt(A); j++){
				while (a%j == 0){
					p[j]++;
					a/=j;
				}
			}
			if (a > 1) {
				p[a]++;
			}
		}
		vector<int> v;
		for (auto [x,y] : p){
			v.push_back(y);
		}
		sort(v.begin(), v.end());
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < v.size(); i++){
			cnt1 += v[i] / 2;
			cnt2 += v[i] % 2;
		}
		cout << cnt1 + cnt2 / 3 << '\n';
	}
	return 0;
}
