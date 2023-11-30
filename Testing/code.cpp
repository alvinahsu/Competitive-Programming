#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../debug.h"
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
		deque<int> v(n);
		for (int i = 0; i < n; i++){
			cin >> v[i];
		}
		long long ans = 0;
		long long sum = accumulate(v.begin(), v.end(), 0ll);
		for (int i = 0; i < n; i++){
			ans += (i+1) * v[i];
		}
		for (int i = 0; i < n; i++){
			//move this to the next
			long long check = ans - (sum - v[i]);
			if (check >= ans){
				// v[i+1] += v[i];
				ans = check;
			}
			sum -= v[i];
		}
		cout << ans << '\n';
	}
	return 0;
}
