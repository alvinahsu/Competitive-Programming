/*
*  File: CFEDU148D
*  Author: Alvin Hsu
*  Date: 05/12/2023 07:33:53
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
	long long n,q;
	cin >> n >> q;
	long long inf = 1e18;
	vector<long long>v(n);
	vector<long long> pref(n+1, inf), suff(n+1, inf);
	long long sum = 0;
	for (int i = 0; i < n; i++){
		cin >> v[i];
		sum += v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++){
		pref[i+1] = min(pref[i], v[i] - i);
	}
	for (int i = n-1; i >= 0; i--){
		suff[i] = min(suff[i+1], v[i]);
	}
	while(q--){
		int k;
		cin >> k;
		if (k < n){
			cout << min(pref[k] + k, suff[k]) << ' ';
		}
		else if ((k - n) % 2 == 0){
			long long mn = pref[n] + k;
			long long s = (sum + n * k - (n * (n-1) / 2));
			s -= (k - n) / 2;
			if (s < 0){
				s = (s - n + 1) / n;
			}
			else {
				s = s / n;
			}
			cout << min(mn,s) << ' ';
		}
		else {
			long long mn = min(pref[n-1] + k, v[n-1]);
			long long s = (sum + (n-1) * k)  - ((n-1) * (n-2) / 2);
			s -= (k - n + 1) / 2;
			if (s < 0){
				s = (s - n + 1) / n;
			}
			else {
				s = s / n;
			}
			cout << min(mn,s) << ' ';
		}
	}
	cout << '\n';
	return 0;
}
