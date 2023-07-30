/*
*  File: USACOUSOpenSilver21B
*  Author: Alvin Hsu
*  Date: 07/30/2023 14:00:47
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
		for (auto &a : v){
			cin >> a;
		}
		sort(v.begin(), v.end());
		//a,b,c,a+b,b+c,c+a,a+b+c
		vector<int>type(7);
		iota(type.begin(), type.end(), 0);
		set<multiset<int>> ans;
		auto check = [&](vector<int> have) -> void{
			if (*min_element(have.begin(), have.end()) <= 0) return;
			if (!(have[0] <= have[1] && have[1] <= have[2])) return;
			bool ok = true;
			ok &= (have[0] + have[1] == have[3]);
			ok &= (have[1] + have[2] == have[4]);
			ok &= (have[0] + have[2] == have[5]);
			ok &= (have[0] + have[1] + have[2] == have[6]);
			if (ok){
				ans.insert({have[0],have[1],have[2]});
			}
		};
		//5040
		do {
			vector<int> curr(7);
			for (int i = 0; i < n; i++){
				curr[type[i]] = v[i];
			}
			bool ok = true;
			if (!curr[0] && !curr[1] && !curr[2]){
				assert(curr[3] && curr[4] && curr[5] && curr[6]);
				curr[0] = curr[3] + curr[5] - curr[6];
				curr[1] = curr[3] + curr[4] - curr[6];
				curr[2] = curr[4] + curr[5] - curr[6]; 
			}
			else {
				for (int i = 0; i < 2; i++){
					if (curr[0]){
						if (curr[1] && !curr[3]) curr[3] = curr[0] + curr[1];
						if (curr[2] && !curr[5]) curr[5] = curr[0] + curr[2];
						if (curr[3] && !curr[1]) curr[1] = curr[3] - curr[0];
						if (curr[5] && !curr[2]) curr[2] = curr[5] - curr[0];
						if (curr[6] && !curr[4]) curr[4] = curr[6] - curr[0];
						if (curr[1] && curr[2] && !curr[6]) curr[6] = curr[0] + curr[1] + curr[2];
					}
					if (curr[1]){
						if (curr[0] && !curr[3]) curr[3] = curr[0] + curr[1];
						if (curr[2] && !curr[4]) curr[4] = curr[1] + curr[2];
						if (curr[3] && !curr[0]) curr[0] = curr[3] - curr[1];
						if (curr[4] && !curr[2]) curr[2] = curr[4] - curr[1];
						if (curr[6] && !curr[5]) curr[5] = curr[6] - curr[1];
						if (curr[0] && curr[2] && !curr[6]) curr[6] = curr[0] + curr[1] + curr[2];
					}
					if (curr[2]){
						if (curr[0] && !curr[5]) curr[5] = curr[0] + curr[2];
						if (curr[1] && !curr[4]) curr[4] = curr[1] + curr[2];
						if (curr[4] && !curr[1]) curr[1] = curr[4] - curr[2];
						if (curr[5] && !curr[0]) curr[0] = curr[5] - curr[2];
						if (curr[6] && !curr[3]) curr[3] = curr[6] - curr[2];
						if (curr[0] && curr[1] && !curr[6]) curr[6] = curr[0] + curr[1] + curr[2];
					}
				}
			}
			check(curr);
		} while(next_permutation(type.begin(), type.end()));
		cout << ans.size() << '\n';
	}
	return 0;
}
