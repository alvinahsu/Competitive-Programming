/*
*  File: CF875B
*  Author: Alvin Hsu
*  Date: 05/29/2023 14:02:52
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
		vector<int>a(n), b(n);
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		for (int i = 0; i < n; i++){
			cin >> b[i];
		}
		map<int,int> A, B;
		int cnt = -1, curr = -1;
		for (int i = 0; i < n; i++){
			if (a[i] != curr){
				A[curr] = max(A[curr], cnt);
				curr = a[i];
				cnt = 1;
			}
			else {
				cnt++;
			}
		}
		A[curr] = max(A[curr], cnt);
		cnt = -1, curr = -1;
		int ans = 0;
		for (int i = 0; i < n; i++){
			if (b[i] != curr){
				B[curr] = max(B[curr], cnt);
				curr = b[i];
				cnt = 1;
			}
			else {
				cnt++;
			}
		}
		B[curr] = max(B[curr], cnt);
		for (int i = 0; i < n; i++){
			ans = max(ans, A[a[i]] + B[a[i]]);
			ans = max(ans, A[b[i]] + B[b[i]]);
		}
		cout << ans << '\n';
		
	}
	return 0;
}
