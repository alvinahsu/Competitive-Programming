/*
*  File: CFEDU157C
*  Author: Alvin Hsu
*  Date: 11/03/2023 07:32:05
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
	int n;
	cin >> n;
	vector<string> v(n);
	vector<vector<string>> s(6);
	for (int i = 0; i < n; i++){
		cin >> v[i];
		s[v[i].size()].push_back(v[i]);
	}
	auto getSum = [&](string ss, int start, int half){
		int sum = 0;
		for (int i = 0; i < ss.size(); i++){
			if (i + start < half){
				sum += ss[i]-'0';
			}
			else {
				sum -= ss[i]-'0';
			}
		}
		return sum;
	};
	int maxSum = 50;
	long long ans = 0;
	for (int i = 1; i <= 5; i++){
		for (int j = 1; j <= 5; j++){
			if ((i+j)%2==0){
				vector<int> cnt(2 * maxSum + 5);
				int half = (i+j)/2;
				for (auto &ss : s[i]){
					cnt[maxSum + getSum(ss,0,half)]++;
				}
				
				for (auto &ss : s[j]){
					ans += cnt[maxSum - getSum(ss,i,half)];
				}
				
			}
		}
	}
	cout << ans << '\n';
	return 0;
}