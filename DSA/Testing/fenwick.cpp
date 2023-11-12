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

struct fentree {
    int size;
    vector<ll> tree;
    vector<ll> arr;
    
    void init(int n) {
        size = n;
        tree.assign(n+1, 0);
        arr.assign(n+1, 0);
    }
    
    void build(vector<int>&a){
        for (int i = 1; i <= a.size(); i++){
            add(i,a[i-1]);
            arr[i] = a[i-1];
        }
    }
    
    void add(int index, int val) {
        arr[index] += val;
        while(index <= size){
            tree[index] += val;
            index += (index&-index);
        }
    }
    
    void set(int index, int val){
        add(index, val - arr[index]);
    }
    
    ll sum(int index){
        ll res = 0;
        while(index > 0){
            res += tree[index];
            index -= (index&-index);
        }
        return res;
    }
};

template<class T>
struct BIT {
    int N; 
    vector<T> data;
    void init(int _N) { 
        N = _N; 
        data.reisze(N); 
    }
    void add(int p, T x) { 
        for (++p;p<=N;p+=p&-p) {
            data[p-1] += x; 
        }
    }
    
    T sum(int l, int r) { 
        return sum(r+1)-sum(l); 
    }
    
    T sum(int r) { 
        T s = 0; 
        for(;r;r-=r&-r)
            s+=data[r-1]; 
        return s; 
    }
    
    int lower_bound(T sum) {
        if (sum <= 0) return -1;
        int pos = 0;
        for (int pw = 1<<25; pw; pw >>= 1) {
            int npos = pos+pw;
            if (npos <= N && data[npos-1] < sum)
                pos = npos, sum -= data[pos-1];
        }
        return pos;
    }
};


struct FenwickTreeOneBasedIndexing {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTreeOneBasedIndexing(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    FenwickTreeOneBasedIndexing(vector<int> a)
        : FenwickTreeOneBasedIndexing(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= (idx & -idx))
            ret += bit[idx];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (++idx; idx < n; idx += (idx & -idx))
            bit[idx] += delta;
    }
};

void solve() {
    int n,q;
    cin >> n >> q;
    vector<int> v(n);
    read(v);
    fentree ft;
    ft.init(n);
    ft.build(v);
    while(q--){
        int a,b,c;
        cin >> a >> b >> c;
        if (a == 1){
            ft.set(b,c);
        }
        else {
            cout << ft.sum(c) - ft.sum(b-1) << endl;
        }
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