#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    FenwickTree(vector<int> a)
        : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++){
            upd(i, a[i]);
        }
    }

    int query(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx){
            ret += bit[idx];
        }
        return ret;
    }

    int query(int l, int r) {
        return query(r) - query(l - 1);
    }

    void upd(int idx, int delta) {
        for (++idx; idx < n; idx += idx & -idx){
            bit[idx] += delta;
        }
    }
    void upd_range(int l, int r, int val) {
        upd(l, val);
        upd(r + 1, -val);
    }

};