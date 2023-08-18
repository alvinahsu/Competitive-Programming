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
		int n,k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<vector<int>> dp(n+1, vector<int>(k+1)), dp2(n+1, vector<int>(k+1));
		vector<vector<int>> mxDp(n+1, vector<int>(k+1)), mxDp2(n+1, vector<int>(k+1));
		vector<int> pref(n+1);
		for (int i = 0; i < n; i++){
			pref[i+1] = pref[i] + (s[i] == '0');
		}
		for (int i = 1; i <= n; i++){
			for (int j = 0; j <= k; j++){
				//no change, can just take previous
				if (s[i-1] == '0'){
					dp[i][j] = dp[i-1][j] + 1;
				}
				//valid change, get consecutive from before
				else if (s[i-1] == '1' && j > 0){
					dp[i][j] = dp[i-1][j-1] + 1;
				}
				//new start
				else {
					dp[i][j] = 0;
				}
				mxDp[i][j] = max(mxDp[i-1][j],dp[i][j]);
				if (j) mxDp[i][j] = max(mxDp[i][j],mxDp[i-1][j-1]);
			}
		}
		for (int i = n; i >= 1; i--){
			for (int j = 0; j <= k; j++){
				//no change, can just take previous
				if (s[i-1] == '0'){
					dp2[i-1][j] = dp2[i][j] + 1;
				}
				//valid change, get consecutive from before
				else if (s[i-1] == '1' && j > 0){
					dp2[i-1][j] = dp2[i][j-1] + 1;
				}
				//new start
				else {
					dp2[i-1][j] = 0;
				}
				
				mxDp2[i-1][j] = max(mxDp2[i][j],dp2[i-1][j]);
				if (j) mxDp2[i-1][j] = max(mxDp2[i-1][j],mxDp2[i-1][j-1]);
				
			}
		}
		vector<int> mxZero(n+1), reach(n+1);
		for (int i = 0; i <= n; i++){
			for (int j = 0; j+i-1 < n; j++){
				int cnt = pref[j+i] - pref[j];
				if (cnt > k) continue;
				int newK = k - cnt;
				assert(newK >= 0);
				reach[i] = 1;
				mxZero[i] = max({mxZero[i], mxDp[j][newK], mxDp2[j+i][newK]});
			}
		}
		for (int i = 1; i <= n; i++){
			int ans = 0;
			for (int j = 0; j <= n; j++) if (reach[j]) {
				ans = max(ans, i * mxZero[j] + j);
			}
			cout << ans << " \n"[i == n];
		}
		
	}
	return 0;
}
