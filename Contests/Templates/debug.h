#include<iostream>
using namespace std;

#define send_help inline
#define dbg(x...) cout << #x << " = {"; _print(x)

inline namespace Output {
send_help void __print(int x) {cout << x;}
send_help void __print(long x) {cout << x;}
send_help void __print(long long x) {cout << x;}
send_help void __print(unsigned x) {cout << x;}
send_help void __print(unsigned long x) {cout << x;}
send_help void __print(unsigned long long x) {cout << x;}
send_help void __print(float x) {cout << x;}
send_help void __print(double x) {cout << x;}
send_help void __print(long double x) {cout << x;}
send_help void __print(char x) {cout << '\'' << x << '\'';}
send_help void __print(const char *x) {cout << '\"' << x << '\"';}
send_help void __print(const string &x) {cout << '\"' << x << '\"';}
send_help void __print(bool x) {cout << (x ? "true" : "false");}

send_help void _print() {cout << "}"<<'\n';} 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << "\n("; __print(x.first); cout << ','; __print(x.second); cout << ")\n";}
template<typename T>
void __print(const T &x) {int f = 0; cout << "\n["; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
} // namespace Output

inline namespace FileIO {
send_help void setIO(string s = "") {
	if (s.size()) {
		freopen((s+".in").c_str(), "r", stdin);
		freopen((s+".out").c_str(), "w", stdout);
	}
}
} // namespace FileIO