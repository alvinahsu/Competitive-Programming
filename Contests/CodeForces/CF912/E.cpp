/*
*  File: CF912E
*  Author: Alvin Hsu
*  Date: 11/30/2023 11:49:50
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
		vector<set<int>> cnt(2);
		int x,y;
		cin >> x >> y;
		for (int i = 0; i < n; i++){
			int xx,yy;
			cin >> xx >> yy;
			int p = xx%2 + yy%2;
			cnt[p%2].insert(i+1);
		}
		int last = (x%2+y%2)%2;
		if (cnt[last].size() >= cnt[last^1].size()){
			cout << "First" << endl;
			last ^= 1;
			for (int i = 0; i < n; i++){
				if (i%2 == 0){
					if (cnt[last].size()){
						cout << *cnt[last].begin() << endl;
						cnt[last].erase(cnt[last].begin());
					}
					else {
						cout << *cnt[last^1].begin() << endl;
						cnt[last^1].erase(cnt[last^1].begin());
					}
				}
				else {
					int p;
					cin >> p;
					if (cnt[last].find(p) != cnt[last].end()){
						cnt[last].erase(p);
					}
					else {
						cnt[last^1].erase(p);
					}
				}
			}
		}
		else {
			cout << "Second" << endl;
			for (int i = 0; i < n; i++){
				if (i&1){
					if (cnt[last].size()){
						cout << *cnt[last].begin() << endl;
						cnt[last].erase(cnt[last].begin());
					}
					else {
						cout << *cnt[last^1].begin() << endl;
						cnt[last^1].erase(cnt[last^1].begin());
					}
				}
				else {
					int p;
					cin >> p;
					if (cnt[last].find(p) != cnt[last].end()){
						cnt[last].erase(p);
					}
					else {
						cnt[last^1].erase(p);
					}
				}
			}
		}
	}
	return 0;
}
