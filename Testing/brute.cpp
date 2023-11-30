#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define dbg(...)
#endif

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++){
			cin >> v[i];
		}
		long long ans = -1e18;
		for (int i = 0; i < (1 << n); i++){
			long long curr = 0, sz = 1, run = 0;
			for (int j = 0; j < n; j++){
				run += v[j];
				if (i&(1<<j)){
					curr += (run * sz);
					sz++;
					run = 0;
				}
			}
			curr += (run * sz);
			ans = max(ans, curr);
		}
		cout << ans << '\n';
	}
	return 0;
}