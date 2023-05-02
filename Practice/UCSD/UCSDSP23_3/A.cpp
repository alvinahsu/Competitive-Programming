/*
*  File: UCSDSP23_3A
*  Author: Alvin Hsu
*  Date: 05/01/2023 17:58:30
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
	int n;
	cin >> n;
	vector<int>v(n);
	multiset<int> s;
	for (auto &a : v){
		cin >> a;
		s.insert(a);
	}
	long long sum = 0;
	for (int i = 0; i < n; i++){
		long long need = v[i] - sum;
		cout << need << " \n"[i == n-1];
		sum += need;
	}
	return 0;
}
