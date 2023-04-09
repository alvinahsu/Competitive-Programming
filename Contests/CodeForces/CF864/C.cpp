/*
*  File: CF864C
*  Author: Alvin Hsu
*  Date: 08/04/2023 21:59:37
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

int query(int x, int y){
	cout << "? " << x << " " << y << '\n';
	cout.flush();
	int d;
	cin >> d;
	return d;
}

void print(int x, int y){
	cout << "! " << x << " " << y << '\n';
	cout.flush();
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		int r = 1, c = 1;
		int d = query(r,c);
		if (d >= n){
			int d2 = query(1, d+1);
			print(d2+1, d+1);
		}
		else if (d >= m){
			int d2 = query(d+1,1);
			print(d+1,d2+1);
		}
		else {
			int d2 = query(1,d+1);
			int d3 = query(d+1,1);
			if (d == d2 && d2 == d3) {
				print(d+1, d+1);
			}
			else if (d2 < d){
				print(d2+1, d+1);
			}
			else {
				print(d+1, d3+1);
			}
		}
		cout.flush();
	}
	return 0;	
}
