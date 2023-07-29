/*
*  File: CF889C1
*  Author: Alvin Hsu
*  Date: 07/29/2023 09:42:17
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

int main(){
	#define int long long
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int idx = 0, minIdx = 0;
		vector<int> v(n);
		bool isNeg = true;
		for (int i = 0; i < n; i++){
			cin >> v[i];
			isNeg &= (v[i] <= 0);
			if (v[i] > v[idx]){
				idx = i;
			}
			if (v[i] < v[minIdx]){
				minIdx = i;
			}
		}
		vector<pair<int,int>> ans;
		if (v[idx] > 0){
			while(v[idx] < 20){
				ans.push_back({idx,idx});
				v[idx] += v[idx];
			}
			for (int i = 0; i < n; i++){
				int last = i ? v[i-1] : -1e9;
				while(v[i] < last){
					ans.push_back({i,idx});
					v[i] += v[idx];
					if (v[i] > v[idx]){
						idx = i;
					}
				}
			}
		}
		if (isNeg && v[minIdx] != 0){
			while(v[minIdx] > -20){
				ans.push_back({minIdx,minIdx});
				v[minIdx] += v[minIdx];
			}
			for (int i = n-1; i >= 0; i--){
				int last = i+1<n ? v[i+1] : 1e9;
				while(v[i] > last){
					ans.push_back({i,minIdx});
					v[i] += v[minIdx];
					if (v[i] < v[minIdx]){
						minIdx = i;
					}
				}
			}
		}
		assert(is_sorted(v.begin(), v.end()));
		assert(ans.size() <= 31);
		cout << ans.size() << '\n';
		for (auto &a : ans){
			cout << a.first+1 << " " << a.second+1 << '\n';
		}
	}
	return 0;
}
