/*
*  File: CF911D
*  Author: Alvin Hsu
*  Date: 11/26/2023 06:27:44
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
		vector<int> v(n);
		for (int i = 0; i < n; i++){
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		long long ans = 0;
		// for (int i = 1; i+1 < n; i++){
		// 	for (int j = 0; j < i; j++){
		// 		int g = gcd(v[j],v[i]);
		// 		ans += 1ll * g * (n-i-1);
		// 	}
		// 	// dbg("CONTRIBUTION: ", ans, i);
		// }
		vector<int> cnt(2e5+5);
		for (int i = 0; i < n; i++){
			vector<int> pos = {1}, pos1 = {v[i]};
			for (int j = 2; 1ll*j*j <= v[i]; j++){
				if (v[i]%j==0){
					cnt[j]++;
					pos.push_back(j);
					if (v[i]/j != j){
						cnt[v[i]/j]++;
						pos1.push_back(v[i]/j);
					}
				}
			}
			cnt[1]++, cnt[v[i]]++;
			
			for (int &f : pos){
				if (2*f <= v[i] && cnt[2*f] < cnt[f]){
					dbg(i,f,cnt[f]-cnt[2*f]);
					ans += (cnt[f] - cnt[2*f]) * f * (n-i-1);
				}
			}
			for (int j = pos1.size()-1; j >= 0; j--){
				int f = pos1[j];
				if (2*f <= v[i] && cnt[2*f] < cnt[f]){
					dbg(i,f,cnt[f]-cnt[2*f]);
					ans += (cnt[f] - cnt[2*f]) * f * (n-i-1);
				}
			}
			
		}
		cout << ans << '\n';
	}
	return 0;
}
