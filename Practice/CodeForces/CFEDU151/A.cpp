/*
*  File: CFEDU151A
*  Author: Alvin Hsu
*  Date: 07/01/2023 14:46:01
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
		int n,k,x;
		cin >> n >> k >> x;
		if (x != 1){
			cout << "YES" << '\n';
			cout << n << '\n';
			for (int i = 1; i <= n; i++){
				cout << 1 << " \n"[i == n];
			}
		}
		else if (n != 1){
			if (n%2 == 0){
				if (k >= 2){
					cout << "YES" << '\n';
					cout << n/2 << '\n';
					for (int i = 1; i <= n/2; i++){
						cout << 2 << ' ';
					}
					cout << '\n';
				}
				else {
					cout << "NO" << '\n';
				}
			}
			else {
				if (k >= 3){
					cout << "YES" << '\n';
					cout << n/2 << '\n';
					for (int i = 1; i < n/2; i++){
						cout << 2 << ' ';
					}
					cout << 3 << '\n';
				}
				else {
					cout << "NO" << '\n';
				}
			}
		}
		else {
			cout << "NO" << '\n';
		}
	}
	return 0;
}
