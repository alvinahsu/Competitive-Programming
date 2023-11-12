#include <bits/stdc++.h>
using namespace std;


//O(n + mlogm)
//dp[i] = lowest val for some LIS with length i
int lis(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> dp(n+1, INF); 
    dp[0] = -INF;

    for (int i = 0; i < n; i++) {
        int l = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        if (dp[l-1] < a[i] && a[i] < dp[l])
            dp[l] = a[i];
    }

    int ans = 0;
    for (int l = 0; l <= n; l++) {
        if (dp[l] < INF)
            ans = l;
    }
    return ans;
}
