#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../Templates/debug.h"
#else
#define dbg(...)
#endif

int dx[8] = {0,0,1,-1,1,-1,-1,1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};
int main(){
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	// Part 1
	// vector<string> v;
	// string s;
	// while(cin >> s){
	// 	v.push_back(s);
	// }
	// int r = v.size(), c = v[0].size();
	// int ans = 0;
	// auto isNum = [&](char c){
	// 	return c >= '0' && c <= '9';
	// };
	
	// auto getNum = [&](int i, int j) -> int {
	// 	int ti = i, tj = j;
	// 	while(j-1 >= 0 && isNum(v[i][j-1])) j--;
	// 	assert(isNum(v[i][j]));
	// 	string num;
	// 	while(j < c && isNum(v[i][j])){
	// 		num += v[i][j];
	// 		v[i][j] = '.';
	// 		j++;
	// 	}
	// 	return stoi(num);
	// };
	
	// auto check = [&](int i, int j) -> void {
	// 	for (int d = 0; d < 8; d++){
	// 		int di = i + dy[d];
	// 		int dj = j +  dx[d];
	// 		if (di >= 0 && di < r && dj >= 0 && dj < c && isNum(v[di][dj])){
	// 			ans += getNum(di,dj);
	// 		}
	// 	}
	// };
	// for (int i = 0; i < r; i++){
	// 	for (int j = 0; j < c; j++){
	// 		if (!(isNum(v[i][j]) || v[i][j] == '.')){
	// 			check(i,j);
	// 		}
	// 	}
	// }
	// cout << ans << '\n';
	
	
	//Part 2
	vector<string> v;
	string s;
	while(cin >> s){
		v.push_back(s);
	}
	int r = v.size(), c = v[0].size();
	int ans = 0;
	auto isNum = [&](char c){
		return c >= '0' && c <= '9';
	};
	
	auto getNum = [&](int i, int j, vector<vector<int>> &vis) -> int {
		int ti = i, tj = j;
		while(j-1 >= 0 && isNum(v[i][j-1])) j--;
		assert(isNum(v[i][j]));
		string num;
		while(j < c && isNum(v[i][j])){
			num += v[i][j];
			vis[i][j] = 1;
			j++;
		}
		return stoi(num);
	};
	
	auto check = [&](int i, int j) -> void {
		vector<vector<int>> vis(r, vector<int>(c));
		vector<int> nums;
		for (int d = 0; d < 8; d++){
			int di = i + dy[d];
			int dj = j +  dx[d];
			if (di >= 0 && di < r && dj >= 0 && dj < c && isNum(v[di][dj]) && !vis[di][dj]){
				nums.push_back(getNum(di,dj,vis));
			}
		}
		if (nums.size() == 2){
			ans += nums[0] * nums[1];
		}
	};
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (v[i][j] == '*'){
				check(i,j);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}