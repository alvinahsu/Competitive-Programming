/*
*  File: CF865D
*  Author: Alvin Hsu
*  Date: 09/04/2023 21:13:12
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

void query(int x){
	cout << "+ " << x << '\n';
	cout.flush();
	int res;
	cin >> res;
}

int ask(int i, int j){
	cout << "? " << i << " " << j << '\n';
	cout.flush();
	int dist;
	cin >> dist;
	return dist;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>ord(n+1);
		int l = 1, r = n;
		for (int i = 1; i <= n; i++){
			if (i&1) {
				ord[i] = r--;
			}
			else {
				ord[i] = l++;
			}
		}
		query(n);
		query(n+1);
		int mx = 0, at = 0;
		for (int i = 2; i <= n; i++){
			int d = ask(1,i);
			if (d > mx){
				mx = d;
				at = i;
			}
		}
		vector<int>p(n+1), q(n+1);
		p[at] = ord[1];
		q[at] = ord[n];
		for (int i = 1; i <= n; i++){
			if (i == at) continue;
			int d = ask(at, i);
			//dist from ord[1]
			p[i] = ord[1 + d];
			//dist from ord[n]
			q[i] = ord[n - d];
		}
		cout << "!";
		for (int i = 1; i <= n; i++){
			cout << " " << p[i];
		}
		for (int i = 1; i <= n; i++){
			cout << " " << q[i];
		}
		cout << '\n';
		cout.flush();
		cin >> n;
	}
	return 0;	
}
