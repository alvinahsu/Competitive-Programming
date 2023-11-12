#include <bits/stdc++.h>
#include <ratio>
using namespace std;
 
#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define f first
#define s second
 
int nxt() {int x; cin >> x; return x;}
string snxt(){string x; cin >> x;return x;}
 
void setIO(){
	#ifndef ONLINE_JUDGE
	FILE * stream;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
}

const int MOD = 1e9+7;

class DSU {
public:
	//parents and sizes for each node
	vector<int> parents;
	vector<int> sizes;
	//intialize size and values for parents and sizes
	DSU(int size) : parents(size), sizes(size, 1) {
		for (int i = 0; i < size; i++) {
			parents[i] = i;
		}
	}
	
	//gets the parent of n
	int find(int n) {
		
		//if parents is itself, return itself
		//otherwise, set and return the top most parent
			return parents[n] == n ? n : (parents[n] = find(parents[n]));
	}
	//links two nodes
	bool merge(int n1, int n2) {
		n1 = find(n1);
		n2 = find(n2);
		//if parent is the same, we can't merge
		if (n1 == n2) {
			return false;
		}
		//can change how we merge the two trees based on sizes
		if (sizes[n1] < sizes[n2]) {
			
		}
		else if (sizes[n1] > sizes[n2]){
			
		}
		else{
			
		}
		//add to new size
		sizes[n1] += sizes[n2];
		//update parent
		parents[n2] = n1;
		return true;
	}
	
	//checks if two nodes are part of same set
	bool sameSet(int n1, int n2){
		//they are same set if parents are the same
		return find(n1) == find(n2);
	}
	
	//gets size of a given set
	int getSize(int n){
		return sizes[n];
	}
};



void solve() {

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