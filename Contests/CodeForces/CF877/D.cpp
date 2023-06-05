/*
*  File: CF877D
*  Author: Alvin Hsu
*  Date: 06/04/2023 10:10:51
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
	set<int> A;
	for (int i = 0; i < n; i++){
		if ((s[i] == '(') != (i%2==0)){
			A.insert(i);
		}
	}
	while(q--){
		int i;
		cin >> i;
		i--;
		if (n&1){
			cout << "NO" << '\n';
			continue;
		}
		//if not in right position, it is now in the right position
		if (A.count(i)) A.erase(i);
		//flipped from right position to wrong position
		else A.insert(i);
		
		bool bad = A.size() && (*A.begin()%2==0 || *prev(A.end())&1);
		cout << (bad ? "NO" : "YES") << '\n';
	}
	return 0;
}
