/*
*  File: CF891B
*  Author: Alvin Hsu
*  Date: 08/07/2023 09:56:12
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
		string s;
		cin >> s;
		int n = s.size();
		int j = n;
		int carry = 0;
		for (int i = n-1; i >= 0; i--){
			int curr = s[i]-'0'+carry;
			s[i] = curr%10+'0'; 
			if (curr >= 5){
				carry = 1;
				j = i;
			}
			else {
				carry = 0;
			}
		}
		if (carry) {
			s = '1' + s;
			j++;
		}
		while(j < s.size()){
			s[j++] = '0';
		}
		cout << s << '\n';
	}
	return 0;
}
