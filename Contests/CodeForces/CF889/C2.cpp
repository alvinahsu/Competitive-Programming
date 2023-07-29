/*
*  File: CF889C2
*  Author: Alvin Hsu
*  Date: 07/29/2023 09:42:17
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
		vector<int> v(n);
		int pos = 0, neg = 0, lo = 0, hi = 0;
		for (int i = 0; i < n; i++){
			cin >> v[i];
			if (v[i] < 0) neg++;
			if (v[i] > 0) pos++;
			if (v[i] > v[hi]) hi = i;
			if (v[i] < v[lo]) lo = i;
		}
		//make all pos, or all neg
		vector<pair<int,int>> ans;
		bool useNeg = useNeg = v[hi] <= -v[lo];
		
		//use whatever is max
	    if (max(pos, neg) <= 12) {
	    	//change at most 12
	        useNeg = v[hi] <= -v[lo];
	    } 
	    // >= 13, already satisfies condition
	    // change 7 numbers
	    else {
	        useNeg = neg >= pos;
	    } 
		if (useNeg) {
			//5
			while(-v[lo] < v[hi]){
				v[lo] *= 2;
				ans.push_back({lo,lo});
			}
			//7
			for (int i = 0; i < n; i++){
				if (v[i] > 0){
					v[i] += v[lo];
					ans.push_back({i,lo});
				}
			}
			//19
			for (int i = n-2; i >= 0; i--){
				ans.push_back({i,i+1});
			}
		}
		else {
			while(v[hi] < -v[lo]) {
				v[hi] *= 2;
				ans.push_back({hi,hi});
			}
			for (int i = 0; i < n; i++){
				if (v[i] < 0){
					v[i] += v[hi];
					ans.push_back({i,hi});
				}
			}
			for (int i = 1; i < n; i++){
				ans.push_back({i,i-1});
			}
		}
		assert(ans.size() <= 31);
		cout << ans.size() << '\n';
		for (auto [x,y] : ans){
			cout << x+1 << " " << y+1 << '\n';
		}
	}
	return 0;
}
