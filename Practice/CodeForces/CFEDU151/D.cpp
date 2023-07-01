/*
*  File: CFEDU151D
*  Author: Alvin Hsu
*  Date: 07/01/2023 14:46:01
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
		vector<long long> v(n);
		for (auto &a : v){
			cin >> a;
		}
		vector<pair<long long,long long>> suff(n+1);
		for (int i = n-1; i >= 0; i--){
			if (v[i] > 0){
				//addition has no affect
				if (abs(suff[i+1].second) >= v[i]) {
					suff[i].first = suff[i+1].first;
				}
				//gain a bit
				else {
					suff[i].first = v[i] - abs(suff[i+1].second) + suff[i+1].first;
				}
				//offset the loss
				suff[i].second = min(0ll,v[i] + suff[i+1].second);
			}
			else {
				//since neg, we can just take the gain of the next
				suff[i].first = suff[i+1].first;
				//add in the negative that we will have
				suff[i].second = suff[i+1].second + v[i];
			}
		}
		long long ans = 0, mx = suff[0].first, sum = 0;
		for (int i = 0; i < n; i++){
			sum += v[i];
			if (sum > 0){
				long long check = sum + suff[i+1].first;
				if (check > mx){
					mx = check;
					ans = sum;
				}
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}
