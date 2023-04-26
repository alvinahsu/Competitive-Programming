#include <bits/stdc++.h>
using namespace std;

//O((N+Q)*sqrt(N))
const int N = 2e5+5;
int blockSize = 101, q = N;
struct Query {
    int l, r, idx;
    bool operator<(Query other) const {
        if(l / blockSize != other.l / blockSize)
            return (l/blockSize) < (other.l/blockSize);
        return r < other.r;
    }
} Q[N];


long long v[N], ans[N];

void remove(int i) {
    
}

void add(int i) {
    
}

void mos () {
    blockSize = sqrt(N);
    sort(Q, Q+q);
    int l = 0, r = -1;
    for (int i = 0; i < q; i++) {
        auto qq = Q[i];
        while (l > qq.l) add(--l);
        while (r < qq.r) add(++r);
        while (l < qq.l) remove(l++);
        while (r > qq.r) remove(r--);
        ans[qq.idx] = N;
    }
}