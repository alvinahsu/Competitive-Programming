#include <bits/stdc++.h>
using namespace std;

#define tcT template <class T
#define tcT2 tcT, class T2

inline namespace Debug {
	tcT2> ostream& operator<<(ostream &out, pair<T,T2> const &p) { return out << "(" << p.first << ", " << p.second << ")"; }
	tcT > ostream& operator<<(ostream &out, vector<T> const &v) {
		out << "["; for(int i = 0; i < v.size(); i++) {if (i) out << ", "; out << v[i];} return out << "]";
	}
} // namespace Debug

inline namespace FileIO {
	void setIO(string s = "") {
		#ifndef ONLINE_JUDGE 			// local FileIO
		if (s.size()) {
			freopen((s+".in").c_str(), "r", stdin);
			freopen((s+".out").c_str(), "w", stdout);
		}
		#endif
	}
} // namespace FileIO
