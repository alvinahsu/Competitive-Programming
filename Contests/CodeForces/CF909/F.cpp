/*
*  File: CF909F
*  Author: Alvin Hsu
*  Date: 11/17/2023 00:21:57
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
		int n,q;
		cin >> n >> q;
		vector<int> d(q);
		for (int i = 0; i < q; i++){
			cin >> d[i];
		}
		vector<int> curr, free;
		for (int i = 1; i < n; i++){
			curr.push_back(i);
			cout << i << " " << i+1 << '\n';
		}
		curr.push_back(n);
		int last = n-1;
		for (int i = 0; i < q; i++){
			if (d[i] == last){
				cout << "-1 -1 -1" << '\n';
			}
			else {
				//add front 2
				if (d[i] > last){
					vector<int> add;
					while(curr.size() + add.size() - 1 != d[i]){
						assert(free.size());
						add.push_back(free.back());
						free.pop_back();
					}
					cout << add.back() << " " << (free.size()?free.back():2) << " " << curr.back() << '\n';
					while(add.size()){
						curr.push_back(add.back());
						add.pop_back();
					}
				}
				//remove to free
				else {
					vector<int> rem;
					while(curr.size() - 1 != d[i]){
						rem.push_back(curr.back());
						curr.pop_back();
					}
					cout << rem.back() << " " << curr.back() << " " << (free.size()?free.back():2) << '\n';
					while(rem.size()){
						free.push_back(rem.back());
						rem.pop_back();
					}
				}
				last = d[i];
			}
		}
	}
	return 0;
}
