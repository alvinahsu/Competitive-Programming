/*
*  File: CF874D
*  Author: Alvin Hsu
*  Date: 05/19/2023 07:31:18
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
		vector<int>v(n);
		for (auto &a : v){
			cin >> a;
		}
		int mxIdx = (v[0] == n ? find(v.begin(), v.end(), n-1) : find(v.begin(), v.end(), n)) - v.begin();
		vector<int> ans = v;
		reverse(ans.begin(), ans.end());
		auto check = [&](vector<int>&a, vector<int>&b){
			if (a < b) {
				a = b;
			}
			else {
				b = a;
			}
		};
		vector<int> temp(n);
		//reverse beginning to i
		for (int i = 0; i < n; i++){
			int k = 0;
			for (int j = i+1; j < n; j++){
				temp[k++] = v[j];
			}
			for (int j = i; j >= 0; j--){
				temp[k++] = v[j];
			}
			check(ans, temp);
		}
		//reverse i to end
		for (int i = 0; i < n; i++){
			int k = 0;
			for (int j = n-1; j >= i; j--){
				temp[k++] = v[j];
			}
			for (int j = 0; j < i; j++){
				temp[k++] = v[j];
			}
			check(ans, temp);
		}
		//keep as post
		int k = 0;
		for (int i = mxIdx; i < n; i++){
			temp[k++] = v[i];
		}
		for (int i = 0; i < mxIdx; i++){
			int dk = k;
			//reverse[i:mxIdx-1]
			for (int j = mxIdx-1; j >= i; j--){
				temp[dk++] = v[j];
			}
			for (int j = 0; j < i; j++){
				temp[dk++] = v[j];
			}
			check(ans, temp);
		}
		for (int i = 0; i < n; i++){
			cout << ans[i] << " \n"[i == n-1];
		}
		
	}
	return 0;
}
