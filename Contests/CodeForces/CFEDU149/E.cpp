/*
*  File: CFEDU149E
*  Author: Alvin Hsu
*  Date: 05/25/2023 09:14:36
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

const int MOD = 998244353;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k;
	cin >> k;
	vector<int>a(1 << k);
	for (int i = 0; i < (1 << k); i++){
		cin >> a[i];
		if (a[i] > 0) a[i]--;
	}
	long long ans = 1;
	for (int st = k-1; st >= 0; st--){
		vector<int> na(1 << st);
		int freeLosers = 1 << st, freeWinners = 0;
		for (int i = 0; i <	 (1 << st); i++){
			int mn = min(a[2*i], a[2*i+1]);
			int mx = max(a[2*i], a[2*i+1]);
			if (mn == -1){
				//loser is fixed
				if (mx >= (1 << st)){
					na[i] = -1;
					freeLosers--;
				}
				//winner is fixed
				else if (mx != -1){
					assert(mx < (1 << st));
					na[i] = mx;
				}
				else {
					assert(mx == -1);
					freeWinners++;
					na[i] = -1;
				}
				continue;
			}
			assert(mn != -1 && mx != -1);
			if ((a[2*i] < (1 << st)) == (a[2*i+1] < (1 << st))) {
				cout << 0 << '\n';
				return 0;
			}
			//winner is fixed at mn
			na[i] = mn;
			freeLosers--;
		}
		//factorial for loser
		for (int j = 1; j <= freeLosers; j++){
			(ans *= (1ll * j)) %= MOD;
		}
		//swap for winners
		for (int j = 1; j <= freeWinners; j++){
			(ans *= 2ll) %= MOD;
		}
		a = na;
	}
	cout << ans << '\n';
	return 0;
}
