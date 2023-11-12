#include <bits/stdc++.h>
#include <queue>

using namespace std;

void solve(){
    string test = "000111010101";
    const int n = test.size();
	bitset<20> s(test);
    cout << s << '\n';
    cout << s.count() << '\n';
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	// setIO();
	
    int tc = 1;
    // cin >> tc;
    for (int i = 1; i <= tc; i++){
        //cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}