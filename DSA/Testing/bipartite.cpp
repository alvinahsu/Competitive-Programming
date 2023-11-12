#include <bits/stdc++.h>
#include <chrono>
#include <numeric>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
 
int nxt(){int x; cin >> x;return x;}
string snxt(){string x; cin >> x;return x;}
 
void setIO(){
	#ifndef ONLINE_JUDGE
	FILE * stream;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
}

bool valid = true;
void dfs(vector<vector<int>> &v, vector<int> &curr, int i, int k){
	//if this number is assigned
	if (curr[i] != -1 || !valid){
		//check if valid
		if (curr[i] != k)
			valid = false;
		return;
	}
	//assigned number
	curr[i] = k;
	//assign res to opposite of this one
	for (auto & a : v[i]){
		dfs(v, curr, a, k^1);
	}
}

void solve() {
	int n,m;
	cin >> n >> m;
	//create graph
	vector<vector<int>> v(n+1);
	vector<int> curr(n+1, -1);
	for (int i = 0;i < m; i++){
		int a,b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	for (int i = 1; i <= n; i++){
		//if we haven't assigned number
		if (curr[i] == -1){
			dfs(v, curr, i, 0);
		}
	}
	if (valid){
		for (int i = 1;i <= n; i++){
			cout << curr[i]+1 << " \n"[i==n];
		}
	}
	else {
		cout << "IMPOSSIBLE" << endl;
	}
}
 
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
	// setIO();
    
	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++){
		//cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}