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
	
	#define int long long
	
	//Part 1
	// string s;
	// getline(cin,s);
	// queue<int> q;
	// stringstream ss(s);
	// string token;
	// while(getline(ss,token,' ')){
	// 	if (isdigit(token[0])){
	// 		q.push(stoll(token));
	// 	}
	// }
	// getline(cin,s);
	// vector<vector<array<int,3>>> conversions;
	// vector<array<int,3>> curr;
	// while(getline(cin,s)){
	// 	if (s.empty()) {
	// 		if (curr.size()){
	// 			conversions.push_back(curr);
	// 			curr.clear();				
	// 		}
	// 	}
	// 	if (isdigit(s[0])){
	// 		stringstream nss(s);
	// 		string ntoken;
	// 		array<int,3> a;
	// 		int i = 0;
	// 		while(getline(nss,token,' ')){
	// 			a[i++] = stoll(token);
	// 		}
	// 		curr.push_back(a);
	// 	}
	// }
	// if (curr.size()) conversions.push_back(curr);
	
	// int n = conversions.size();
	// for (int i = 0; i < n; i++){
	// 	int sz = q.size();
	// 	while(sz--){
	// 		auto c = q.front(); q.pop();
	// 		bool isMapped = false;
	// 		for (auto [dest,start,size] : conversions[i]){
	// 			if (start <= c && c < start+size){
	// 				isMapped = true;
	// 				q.push(dest + (c - start));
	// 			}
	// 		}
	// 		if (!isMapped){
	// 			q.push(c);
	// 		}
	// 	}
	// }
	// int ans = LLONG_MAX;
	// while(q.size()){
	// 	ans = min(ans, q.front());
	// 	q.pop();
	// }
	// cout << ans << '\n';
	
	//Part 2
	string s;
	getline(cin,s);
	queue<pair<int,int>> q;
	stringstream ss(s);
	string token;
	int last = -1;
	while(getline(ss,token,' ')){
		if (isdigit(token[0])){
			if (last == -1) last = stoll(token);
			else {
				q.push({last,last+stoll(token)-1});
				last = -1;
			}
		}
	}
	getline(cin,s);
	vector<vector<array<int,3>>> conversions;
	vector<array<int,3>> curr;
	while(getline(cin,s)){
		if (s.empty()) {
			if (curr.size()){
				conversions.push_back(curr);
				curr.clear();				
			}
		}
		if (isdigit(s[0])){
			stringstream nss(s);
			string ntoken;
			array<int,3> a;
			int i = 0;
			while(getline(nss,token,' ')){
				a[i++] = stoll(token);
			}
			curr.push_back(a);
		}
	}
	if (curr.size()) conversions.push_back(curr);
	int n = conversions.size();
	for (int i = 0; i < n; i++){
		int sz = q.size();
		while(sz--){
			auto [l,r] = q.front(); q.pop();
			int minL = LLONG_MAX, maxR = -LLONG_MAX;
			for (auto [dest,start,size] : conversions[i]){
				int nl = max(l,start);
				int nr = min(r,start+size-1);
				// dbg(l,r,start,start+size-1, nl, nr);
				if (nl <= nr){
					minL = min(minL, nl);
					maxR = max(maxR, nr);
					int diff = nr - nl;
					int off = nl - start;
					q.push({dest+off,dest+off+diff});
				}
			}
			if (minL > l){
				int d = minL != LLONG_MAX ? minL - 1 - l : r - l;
				q.push({l,l+d});
			}
			if (maxR < r && maxR >= l){
				q.push({maxR+1,r});
			}
		}
	}
	int ans = LLONG_MAX;
	while(q.size()){
		ans = min(ans, q.front().first);
		q.pop();
	}
	cout << ans << '\n';
	return 0;
}