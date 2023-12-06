/*
*  File: CFEDU159D
*  Author: Alvin Hsu
*  Date: 12/04/2023 13:44:28
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
	int n,q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<array<int,4>> suff(n+1);
	for (int i = n-1; i >= 0; i--){
		suff[i] = suff[i+1];
		if (s[i] == 'U') suff[i][0]++;
		if (s[i] == 'D') suff[i][1]++;
		if (s[i] == 'L') suff[i][2]++;
		if (s[i] == 'R') suff[i][3]++;
	}
	//inclusive
	auto getDelta = [&](int l, int r){
		int du = suff[l][0] - suff[r][0];
		int dd = suff[l][1] - suff[r][1];
		int dl = suff[l][2] - suff[r][2];
		int dr = suff[l][3] - suff[r][3];
		return make_pair(dr - dl, du - dd);
	};
	int sx = 0, sy = 0;
	map<pair<int,int>, vector<int>> points;
	points[{0,0}].push_back(-1);
	for (int i = 0; i < n; i++){
		if (s[i] == 'U') sy++;
		if (s[i] == 'D') sy--;
		if (s[i] == 'L') sx--;
		if (s[i] == 'R') sx++; 
		points[{sx,sy}].push_back(i);
	}
	map<pair<int,int>, vector<int>> inSuff;
	sx = 0, sy = 0;
	for (int i = n-1; i >= 0; i--){
		if (s[i] == 'U') sy++;
		if (s[i] == 'D') sy--;
		if (s[i] == 'L') sx--;
		if (s[i] == 'R') sx++; 
		inSuff[{sx,sy}].push_back(i);
	}
	for (auto &[x,y] : inSuff){
		sort(y.begin(), y.end());
	}
	
	while(q--){
		int x,y,l,r;
		cin >> x >> y >> l >> r;
		l--, r--;
		bool ok = false;
		//check prefix/suffix
		if (points[{x,y}].size() && (points[{x,y}][0] < l || points[{x,y}].back() > r)){
			ok = true;
		}
		//lies within the reversed string
		auto delta = getDelta(r+1, n);
		auto curr = getDelta(0, l);
		int dx = x - (curr.first - delta.first);
		int dy = y - (curr.second - delta.second);
		auto it = lower_bound(inSuff[{dx,dy}].begin(), inSuff[{dx,dy}].end(), l);
		if (it != inSuff[{dx,dy}].end() && *it <= r){
			ok = true;
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}

