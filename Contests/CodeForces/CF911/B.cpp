/*
*  File: CF911B
*  Author: Alvin Hsu
*  Date: 11/26/2023 06:27:44
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
		vector<int> v(3);
		for (int i = 0; i < 3; i++){
			cin >> v[i];
		}
		bool ok1 = abs(v[1]-v[2])%2==0 && (v[0]+(min(v[1],v[2])-(abs(v[1]-v[2])/2) >= (abs(v[1]-v[2])/2)));
		bool ok2 = abs(v[0]-v[2])%2==0 && (v[1]+(min(v[0],v[2])-(abs(v[0]-v[2])/2) >= (abs(v[0]-v[2])/2)));
		bool ok3 = abs(v[1]-v[0])%2==0 && (v[2]+(min(v[1],v[0])-(abs(v[1]-v[0])/2) >= (abs(v[1]-v[0])/2)));
		
		cout << ok1 << " " << ok2 << " " << ok3 << '\n';
	}
	return 0;
}
