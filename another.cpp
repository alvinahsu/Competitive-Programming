#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,s;
	cin >> n >> s;
	vector<int> h(n), b(s);
	for (auto &it : h){
		cin >> it;
	}
	for (auto &it : b){
		cin >> it;
	}
	for (int i = 0; i < (1 << n); i++){
		vector<int> sum(s);
		if (__builtin_popcount(i) == s){
			int end = true;
			int k = 0;
			for (int j = 0; j < n; j++){
				if (i&(1<<j)){
					if (end){
						k++;
					}
					end ^= 1;
					if (k < s){
						sum[k] += h[j];
					}
				}
			}
			bool ok = true;
			for (int j = 0; j < s; j++){
				ok &= (sum[j] == b[j]);
				// cout << sum[j] << " ";
			}
			// cout << '\n';
			if (ok){
				cout << 1 << '\n';
			}
		}	
	}
		
	return 0;
}

