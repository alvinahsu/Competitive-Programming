/*
*  File: CFEDU149D
*  Author: Alvin Hsu
*  Date: 05/25/2023 07:22:49
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
		string s;
		cin >> s;
		int L = count(s.begin(), s.end(), '(');
		int R = count(s.begin(), s.end(), ')');
		bool ok = L == R;
		if (!ok){
			cout << -1 << '\n';
			continue;
		}
		int k = 1;
		int ll = L, rr = R;
		int takeL = 0;
		vector<int> colors(n);
		bool took = false;
		for (int i = 0; i < n; i++){
			if (s[i] == '(' && rr > takeL){
				colors[i] = k;
				took = 1;
				takeL++;
			}
			else if (s[i] == ')' && takeL){
				colors[i] = k;
				took = 1;
				takeL--;
			}
			if (s[i] == '(') ll--;
			else rr--;
		}
		if (took && count(colors.begin(), colors.end(), 0) != 0){
			k++;
			for (int i = 0; i < n; i++){
				if (!colors[i]) colors[i] = k;
			}
		}
		else if (!took && count(colors.begin(), colors.end(), 0) == n){
			for (int i = 0; i < n; i++){
				colors[i] = k;
			}
		}
		int dK = 1;
		ll = L, rr = R;
		int takeR = 0;
		vector<int> dColors(n);
		took = false;
		for (int i = 0; i < n; i++){
			if (s[i] == ')' && ll > takeR){
				dColors[i] = dK;
				took = 1;
				takeR++;
			}
			else if (s[i] == '(' && takeR){
				dColors[i] = dK;
				took = 1;
				takeR--;
			}
			if (s[i] == '(') ll--;
			else rr--;
		}
		if (took && count(dColors.begin(), dColors.end(), 0) != 0){
			dK++;
			for (int i = 0; i < n; i++){
				if (!dColors[i]) dColors[i] = dK;
			}
		}
		else if (!took && count(dColors.begin(), dColors.end(), 0) == n){
			for (int i = 0; i < n; i++){
				dColors[i] = dK;
			}
		}
		if (dK < k) {
			k = dK;
			colors = dColors;
		}
		cout << k << '\n';
		for (int i = 0; i < n; i++){
			cout << colors[i] << " \n"[i == n-1];
		}
		
	}
	return 0;
}
