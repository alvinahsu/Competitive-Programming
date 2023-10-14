#include <bits/stdc++.h>
using namespace std;

const int N = 105, inf = 1e9;
int n;
int dp[N][N]; //dp[i][i] = 0, dp[i][j] = edge(i,j)
void floyd(){
	for (int k = 0; k < n; ++k) {
	    for (int i = 0; i < n; ++i) {
	        for (int j = 0; j < n; ++j) {
	            if (dp[i][k] < inf && dp[k][j] < inf){
	                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]); 
	            }
	        }
	    }
	}
}