/*
*  File: CFEDU150C
*  Author: Alvin Hsu
*  Date: 06/12/2023 13:25:09
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
	map<char,int> mp = {{'A',1}, {'B',10},{'C',100},{'D',1000},{'E',10000}};
	while(t--){
		string s;
		cin >> s;
		int n = s.size();
		vector<vector<long long>> pref(n+1, vector<long long>(5)), suff(n+1,  vector<long long>(5));
		vector<vector<int>> good(n+1, vector<int>(6));
		for (int i = 0; i < n; i++){
			good[i+1] = good[i];
			good[i+1][s[i]-'A']++;
			for (char c = 'A'; c < s[i]; c++){
				good[i+1][c-'A'] = 0;
			}
		}
		for (int i = 0; i < n; i++){
			pref[i+1] = pref[i];
			pref[i+1][s[i]-'A']++;
		}
		for (int i = n-1; i >= 0; i--){
			suff[i] = suff[i+1];
			suff[i][s[i]-'A']++;
		}
		vector<long long> post(n+1);
		vector<int> S(n);
		for (int i = n-1; i >= 0; i--){
			post[i] += post[i+1];
			bool sub = false;
			for (char c = s[i]+1; c <= 'E'; c++){
				if (suff[i][c-'A']){
					sub = true;
				}
			}
			S[i] = sub;
			post[i] += (sub ? -mp[s[i]] : mp[s[i]]);
		}
		long long ans = post[0];
		for (int i = 0; i < n; i++){
			//not including s[i]
			vector<long long> before = pref[i];
			vector<long long> after = suff[i+1];
			//make s[i] smaller
			for (char j = 'A'; j < s[i]; j++){
				//offset s[i] value
				long long curr = post[0] + (S[i] ? mp[s[i]] : -mp[s[i]]);
				char mx = 'A'-1;
				for (char c = 'A'; c <= 'E'; c++){
					if (after[c-'A']) mx = c;
				}
				//only numbers from [k,s[i]) are affected
				for (char k = j; k < s[i]; k++){
					//comparing k against j, k >= j, only add if it was subtracted bfore
					//and that is when k 
					if (k >= mx){
						curr += (2 * good[i][k-'A'] * mp[k]);
					}
				}
				//check s[i] contribution
				bool sub = j < mx;
				curr += (sub ? -mp[j] : mp[j]);
				ans = max(ans, curr);
			}
			//make s[i] bigger
			for (char j = s[i]+1; j <= 'E'; j++){
				long long curr = post[0] + (S[i] ? mp[s[i]] : -mp[s[i]]);
				char mx = 'A'-1;
				for (char c = 'A'; c <= 'E'; c++){
					if (after[c-'A']) mx = c;
				}
				//only numbers from [s[i],k] are affected
				for (char k = s[i]; k < j; k++){
					//comparing k against j, k < j, only subtract if that was added before
					//and that is when k >= mx
					if (k >= mx){
						curr -= (2 * good[i][k-'A'] * mp[k]);
					}
				}
				bool sub = j < mx;
				curr += (sub ? -mp[j] : mp[j]);
				ans = max(ans, curr);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}