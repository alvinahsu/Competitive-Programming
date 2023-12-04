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
	// string s;
	// int ans = 0;
	// while(getline(cin, s)){
	// 	s[s.find(':')] = '|';
	// 	stringstream ss(s);
	// 	string token;
	// 	vector<string> v;
	// 	while(getline(ss,token,'|')){
	// 		v.push_back(token);
	// 	}
	// 	assert(v.size() == 3);
	// 	vector<int> good(101);
	// 	int currTot = 0;
	// 	for (int i = 1; i < v.size(); i++){
	// 		string num;
	// 		for (int j = 0; j < v[i].size(); j++){
	// 			while(j < v[i].size() && v[i][j] >= '0' && v[i][j] <= '9'){
	// 				num += v[i][j];
	// 				j++;
	// 			}
	// 			if (i == 1 && num.size()){
	// 				good[stoi(num)] = 1;
	// 			}
	// 			if (i == 2 && num.size()){
	// 				if (good[stoi(num)]){
	// 					if (currTot == 0) currTot = 1;
	// 					else currTot *= 2;
	// 				}
	// 			}
	// 			num = "";
	// 		}
	// 	}
	// 	ans += currTot;
	// }
	// cout << ans << '\n';

	//Part 2
	string s;
	vector<int> have(501, 1);
	int id = 0, ans = 0;
	while(getline(cin, s)){
		s[s.find(':')] = '|';
		stringstream ss(s);
		string token;
		vector<string> v;
		while(getline(ss,token,'|')){
			v.push_back(token);
		}
		assert(v.size() == 3);
		vector<int> good(101);
		int currTot = 0;
		id = stoi(v[0].substr(5));
		for (int i = 1; i < v.size(); i++){
			string num;
			for (int j = 0; j < v[i].size(); j++){
				while(j < v[i].size() && v[i][j] >= '0' && v[i][j] <= '9'){
					num += v[i][j];
					j++;
				}
				if (i == 1 && num.size()){
					good[stoi(num)] = 1;
				}
				if (i == 2 && num.size() && good[stoi(num)]){
					currTot++;
				}
				num = "";
			}
		}
		for (int i = id+1; i <= id+currTot; i++){
			have[i] += have[id];
		}		
	}
	for (int i = 1; i <= id; i++){
		ans += have[i];
	}
	cout << ans << '\n';
	return 0;
}