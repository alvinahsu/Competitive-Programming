/*
*  File: CF878E
*  Author: Alvin Hsu
*  Date: 06/11/2023 10:24:26
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
	int T;
	cin >> T;
	while(T--){
		string s1,s2;
		cin >> s1 >> s2;
		int n = s1.size();
		vector<int> block(n);
		int bad = 0;
		map<int,int> mxBlock;
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
		for (int i = 0; i < n; i++){
			bad += s1[i] != s2[i];
		}
		int t,q;
		cin >> t >> q;
		for (int i = 0; i < q; i++){
			while(pq.size() && pq.top().first == i){
				auto &[x,y] = pq.top(); pq.pop();
				if (mxBlock[y] == x){
					block[y] = 0;
					if (s1[y] != s2[y]) bad++;
				}
			}
			int x;
			cin >> x;
			if (x == 1){
				int pos;
				cin >> pos;
				pos--;
				block[pos] = 1;
				pq.push({i+t, pos});
				mxBlock[pos] = i+t;
				if (s1[pos] != s2[pos]) bad--;
			}
			else if (x == 2){
				int str1, str2;
				int pos1, pos2;
				cin >> str1 >> pos1 >> str2 >> pos2;
				pos1--, pos2--;
				bad += s1[pos1] == s2[pos1];
				bad += s1[pos2] == s2[pos2];
				
				if (str1 == 2 && str2 == 2){
					swap(s2[pos1], s2[pos2]);
				}
				else if (str1 == 1 && str2 == 1){
					swap(s1[pos1], s1[pos2]);
				}
				else if (str1 == 1 && str2 == 2){
					swap(s1[pos1], s2[pos2]);
				}
				else {
					swap(s2[pos1], s1[pos2]);
				}
				bad -= s1[pos1] == s2[pos1];
				bad -= s1[pos2] == s2[pos2];
			}
			else {
				cout << (!bad ? "YES" : "NO") << '\n';
			}
		}
		
	}
	return 0;
}
