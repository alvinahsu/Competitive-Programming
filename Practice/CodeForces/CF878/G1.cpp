	/*
	*  File: CF878G1
	*  Author: Alvin Hsu
	*  Date: 06/11/2023 15:03:47
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
		int x;
		cin >> x;
		map<int,int> pos;
		int cnt = 1;
		pos[x] = cnt;
		for (int i = 0; i <= 1000; i++){
			cout << "+ 1" << endl;
			cnt += 1;
			
			int n;
			cin >> n;
			if (pos[n]){
				cout << "! " << cnt-1 << endl;
				return 0;
			}
			pos[n] = cnt;
		}
		for (int i = 0; i <= 1000; i++){
			cout << "+ 1000" << endl;
			cnt += 1000;
			int n;
			cin >> n;
			if (pos[n]){
				cout << "! " << (cnt - pos[n]) << endl;
				return 0;
			}
			pos[n] = cnt;
		}
		return 0;
	}
