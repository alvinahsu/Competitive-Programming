#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../Templates/debug.h"
#else
#define dbg(...)
#endif

int main(){
	
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	//Part 1
	// int ans = 0;
	// string s;
	// while(cin >> s){
	// 	int n = s.size();
	// 	vector<int> nums;
	// 	for (int j = 0; j < n; j++){
	// 		if (s[j] >= '0' && s[j] <= '9'){
	// 			nums.push_back(s[j]-'0');
	// 		}
	// 	}
	// 	assert(nums.size());
	// 	ans += nums[0] * 10 + nums.back();
		
	// }
	// cout << ans << '\n';
	
	
	//Part 2
	map<string, int> mp;
	mp["one"] = 1;
	mp["two"] = 2;
	mp["three"] = 3;
	mp["four"] = 4;
	mp["five"] = 5;
	mp["six"] = 6;
	mp["seven"] = 7;
	mp["eight"] = 8;
	mp["nine"] = 9;
	int ans = 0;
	string s;
	while(cin >> s){
		int n = s.size();
		vector<int> nums;
		for (int j = 0; j < n; j++){
			if (s[j] >= '0' && s[j] <= '9'){
				nums.push_back(s[j]-'0');
			}
			else {
				for (auto [x,y] : mp){
					if (j + x.size() <= n && s.substr(j, x.size()) == x){
						nums.push_back(y);
					}
				}
			}
		}
		assert(nums.size());
		ans += nums[0] * 10 + nums.back();
		
	}
	cout << ans << '\n';

	return 0;
}