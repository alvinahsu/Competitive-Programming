/*
*  File: CF901B
*  Author: Alvin Hsu
*  Date: 11/11/2023 15:53:38
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
		int n,m,k;
		cin >> n >> m >> k;
		vector<int> a(n), b(m);
		for (auto &it : a){
			cin >> it;
		}
		for (auto &it : b){
			cin >> it;
		}
		multiset<int> aa(a.begin(), a.end()), bb(b.begin(), b.end());
		vector<long long> iteration(101);
		auto getSum = [&](){
			return accumulate(aa.begin(), aa.end(), 0ll);
		};
		for (int i = 1; i <= 100; i++){
			int mnA = *aa.begin(), mxA = *prev(aa.end());
			int mnB = *bb.begin(), mxB = *prev(bb.end());
			//jely turn
			if (i&1){
				if (mnA < mxB){
					aa.erase(aa.find(mnA));
					aa.insert(mxB);
					bb.erase(bb.find(mxB));	
					bb.insert(mnA);
				}
			}
			//other turn
			else {
				if (mnB < mxA){
					bb.erase(bb.find(mnB));
					bb.insert(mxA);
					aa.erase(aa.find(mxA));
					aa.insert(mnB);
				}
				
			}
			iteration[i] = getSum();
		}
		cout << iteration[(((k-1)+(int)100)%(int)100)+1] << '\n';
		
	}
	return 0;
}
