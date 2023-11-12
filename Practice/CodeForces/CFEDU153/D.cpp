/*
*  File: CFEDU153D
*  Author: Alvin Hsu
*  Date: 08/20/2023 10:44:49
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

const int inf = 1e9;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    string s;
    cin >> s;
    
    int n = s.size();
    
    //# of 1
    int c1 = count(s.begin(), s.end(), '1');
    //# of 0
    int c0 = n - c1;
    
    //pair of 10s
    //(# of total pairs) - (# of pairs of 0) + (# of pairs of 1)
    int need = (n * (n - 1) / 2 - c0 * (c0 - 1) / 2 + c1 * (c1 - 1) / 2) / 2;
    dbg(n,need);
    
    //dp[i][j]
    //# min swap having i ones, and j [10] pairs
    vector dp(c1 + 1, vector<int>(need + 1, inf));
    dp[0][0] = 0;
    
    for (int i = 0; i < n; i++) {
    	//# of 1s
        for (int j = c1 - 1; j >= 0; j--) {
        	//# of [10] pairs
            for (int k = 0; k + i <= need; k++) {
                dp[j + 1][k + i] = min(dp[j + 1][k + i], dp[j][k] + (s[i] == '0'));
            }
        }
    }
    cout << dp[c1][need] << "\n";
	return 0;
}
