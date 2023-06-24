/*
*  File: CFCodeTonR5A
*  Author: Alvin Hsu
*  Date: 06/24/2023 09:59:00
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
		int n,m;
		cin >> n >> m;
		multiset<int> a, b;
		for (int i = 0; i < n; i++){
			int x;
			cin >> x;
			a.insert(x);
		}
		for (int i = 0; i < m; i++){
			int x;
			cin >> x;
			b.insert(x);
		}
		bool A = true;
		while(a.size() && b.size()){
			if (A){
				auto last = *--a.end();
				a.erase(--a.end());
				auto nxt = lower_bound(b.begin(), b.end(), last);
				if (nxt != b.begin()) nxt--;
				auto bLast = *nxt;
				b.erase(nxt);
				if (last - bLast > 0) {
					a.insert(last - bLast);
				}
				if (bLast - last > 0){
					b.insert(bLast - last);
				}
			}
			else {
				auto last = *--b.end();
				b.erase(--b.end());
				auto nxt = lower_bound(a.begin(), a.end(), last);
				if (nxt != a.begin()) nxt--;
				auto aLast = *nxt;
				a.erase(nxt);
				if (last - aLast > 0) {
					b.insert(last - aLast);
				}
				if (aLast - last > 0){
					a.insert(aLast - last);
				}
			}
			A ^= 1;
		}
		if (a.empty() && b.empty()){
			cout << "Draw" << '\n';
		}
		else if (a.size()){
			cout << "Tsondu" << '\n';
		}
		else {
			cout << "Tenzing" << '\n';
		}
	}
	return 0;
}
