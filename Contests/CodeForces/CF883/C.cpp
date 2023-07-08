/*
*  File: CF883C
*  Author: Alvin Hsu
*  Date: 07/07/2023 10:32:34
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
	long long t;
	cin >> t;
	while(t--){
		long long n,m,h;
		cin >> n >> m >> h;
		vector<vector<long long>>v(n, vector<long long>(m));
		for (long long i = 0; i < n; i++){
			for (long long j = 0; j < m; j++){
				cin >> v[i][j];
			}
		}
		for (long long i = 0; i < n; i++){
			sort(v[i].begin(), v[i].end());
		}
		vector<array<long long,3>> res;
		for (long long i = 0; i < n; i++){
			long long sum = 0;
			long long pen = 0;
			long long cnt = 0;
			for (long long j = 0; j < m; j++){
				if (sum + v[i][j] > h) break;
				sum += v[i][j];
				pen += sum;
				cnt++;
			}
			res.push_back({cnt, pen, i+1});
		}
		sort(res.begin(), res.end(), [&](auto a, auto b) {
			if (a[0] == b[0]) return a[1] < b[1];
			return a[0] > b[0];
		});
		long long place = 1;
		for (long long i = 0; i < n; i++){
			long long c = res[i][0], s = res[i][1], idx = res[i][2];
			if (idx == 1) {
				while(i > 0 && res[i][0] == res[i-1][0] && res[i][1] == res[i-1][1]){
					i--;
					place--;
				}
				break;
			}
			place++;
		}
		cout << place << '\n';
	}
	return 0;
}
