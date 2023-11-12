/*
*  File: CF891F
*  Author: Alvin Hsu
*  Date: 08/07/2023 09:56:12
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
		map<long long,long long> cnt;
		for (int i = 0; i < n; i++){
			int x;
			cin >> x;
			cnt[x]++;
		}
		int q;
		cin >> q;
		while(q--){
			long long x,y;
			cin >> x >> y;
			long long sqt = x * x - 4 * y;
			//no solution
			if (sqt < 0){
				cout << 0 << ' ';
			}
			//one solution
			else if (sqt == 0){
				if (x&1){
					cout << 0 << ' ';
				}
				else {
					cout << cnt[x/2]*(cnt[x/2]-1)/2 << ' ';
				}
			}
			//two solution
			else {
				long long r = sqrt(sqt);
				if (r * r == sqt){
					long long a = x + r;
					if (a&1){
						cout << 0 << ' ';
					}
					else {
						a /= 2;
						long long b = (x - r) / 2;
						if (a == b){
							cout << cnt[a] * (cnt[b]-1) / 2 << ' ';
						}
						else {
							cout << cnt[a] * cnt[b] << ' ';
						}
					}
				}
				else {
					cout << 0 << ' ';
				}
				
			}
		}
		cout << '\n';
	}
	return 0;
}
