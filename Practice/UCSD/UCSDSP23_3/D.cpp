/*
*  File: UCSDSP23_3D
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
	int n,m,k;
	cin >> n >> m >> k;
	vector<int>v(n);
	for (auto &a : v){
		cin >> a;
	}
	long long sum = 0;
	multiset<int> ms, aside;
	int i = 0;
	for (; i < m; i++){
		ms.insert(v[i]);
		sum += v[i];
		if (ms.size() > k){
			sum -= *prev(ms.end());
			aside.insert(*prev(ms.end()));
			ms.erase(prev(ms.end()));
		}
	}
	cout << sum << " ";
	int l = 0;
	for (; i < n; i++){
		if (ms.find(v[l]) != ms.end()){
			ms.erase(ms.find(v[l]));	
			sum -= v[l];
		}
		if (aside.find(v[l]) != aside.end()) {
			aside.erase(aside.find(v[l]));
		}
		l++;
		while(ms.size() < k && aside.size()){
			sum += *aside.begin();
			ms.insert(*aside.begin());
			aside.erase(aside.begin());
		}
		ms.insert(v[i]);
		sum += v[i];
		if (ms.size() > k){
			sum -= *prev(ms.end());
			aside.insert(*prev(ms.end()));
			ms.erase(prev(ms.end()));
		}
		cout << sum << " \n"[i == n-1];
	}
	return 0;
}
