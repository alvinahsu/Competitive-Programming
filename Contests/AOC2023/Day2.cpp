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
	// map<string,int> limit;
	// limit["red"] = 12;
	// limit["green"] = 13;
	// limit["blue"] = 14;
	// int ans = 0;
	// string s;
	// while(getline(cin, s)){
	// 	s[s.find(':')] = ';';
	// 	stringstream ss(s);
	// 	string token;
	// 	vector<string> tokens;
	// 	while(getline(ss, token, ';')){
	// 		tokens.push_back(token);
	// 	}
	// 	int id = stoi(tokens[0].substr(5));
	// 	bool ok = true;
		
	// 	for (int i = 1; i < tokens.size(); i++){
	// 		stringstream sst(tokens[i]);
	// 		string play;
	// 		vector<string> plays;
	// 		map<string,int> have;
	// 		while(getline(sst, play, ',')){
	// 			assert(play[0] == ' ');
	// 			play = play.substr(1);
	// 			int space = play.find(' ');
	// 			int chosen = stoi(play.substr(0, space));
	// 			string color = play.substr(space+1);
	// 			ok &= (have[color] += chosen <= limit[color]);
	// 		}
	// 	}
	// 	if (ok){
	// 		ans += id;
	// 	}
	// }	
	// cout << ans << '\n';
	
	//Part 2
	int ans = 0;
	string s;
	while(getline(cin, s)){
		s[s.find(':')] = ';';
		stringstream ss(s);
		string token;
		vector<string> tokens;
		while(getline(ss, token, ';')){
			tokens.push_back(token);
		}
		int id = stoi(tokens[0].substr(5));
		bool ok = true;
		
		map<string,int> have;
		for (int i = 1; i < tokens.size(); i++){
			stringstream sst(tokens[i]);
			string play;
			vector<string> plays;
			while(getline(sst, play, ',')){
				assert(play[0] == ' ');
				play = play.substr(1);
				int space = play.find(' ');
				int chosen = stoi(play.substr(0, space));
				string color = play.substr(space+1);
				have[color] = max(have[color], chosen);
			}
		}
		int contr = 1;
		for (auto [color,chosen] : have){
			contr *= chosen;
		}
		ans += contr;
	}	
	cout << ans << '\n';
	
	return 0;
}