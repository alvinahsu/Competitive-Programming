#include <bits/stdc++.h>
using namespace std;

//using types 
using ll = long long;
using ld = long double;
using ull = unsigned long long;

//define operators
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mp(x1,x2) make_pair(x1,x2)
#define f first
#define s second

//const values
const ll INF = 1e18+7;
const int MOD = 1e9+7;

int nxt(){int x; cin >> x; return x;}
string snxt(){string x; cin >> x; return x;}
char cnxt(){char x; cin >> x; return x;}
void read(vector<int>&v){for(auto& a:v){cin >> a;}}
void read(vector<int>&v, int x){for(auto i=x;i<v.size();i++){cin>>v[i];}}
 
 
void setIO(){
    #ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    #endif
}

struct segtree {
private:
	static int size;
	vector<ll> sums;
public:
	void init(ll n){
		size = 1;
		while(size < n) size <<= 1;
		sums.assign(2*size, INF);
	}
	
	void print(){
		for (int i = 0;i < sums.size(); i++){
			cout << sums[i] << " \n"[i == sums.size()-1];
		}
	}
	
	void build(vector<int>&a, int node = 0, int left = 0, int right = size){
		//leaf node
		if (left == right){
			//take into account padding
			if (left < a.size()) {
				sums[node] = a[left];
			}
			return;
		}
		//non-left, traverse each side
		int mid = left + (right - left) / 2;
		build(a, node*2+1, left, mid);
		build(a, node*2+2, mid+1, right);
		//update node
		sums[node] = min(sums[node*2+1],sums[node*2+2]);
	}
	
	//set the ith index in a to be value of v, we are currently at node in tree
	//with left and right as our left and right bounds in the binary tree
	void set(int i, int v, int node = 0, int left = 0, int right = size) {
		//leaf node (base case)
		if (left == right){
			sums[node] = v;
			return;
		}
		int mid = left + (right - left) / 2;
		//if index we are looking for is to the left of our current mid
		if (i <= mid){
			set(i,v,node*2+1, left, mid);
		}
		//if index we are looking for is to the right of our current mid
		else {
			set(i,v,node*2+2, mid+1, right);
		}
		//update node
		sums[node] = min(sums[node*2+1], sums[node*2+2]);
	}
	
	ll get(int l, int r, int node = 0, int left = 0, int right = size){
		//outside of range
		if (l > right || r < left) return INF;
		//inside range
		if (left >= l && right <= r) return sums[node];
		//partial range
		int mid = left + (right - left) / 2;
		return min(get(node*2+1, l, r, left, mid), get(node*2+2, l, r, mid+1, right));
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