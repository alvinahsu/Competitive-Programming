/**
 * File: SegTree.h
 * Author: Alvin Hsu
 * 
 * Description: Segment Tree which supports 1D point update on associative operations
 * Time Complexity: O(logn)
 * 
 * Methods:
 *  SegTree (constructor): Sets seg size (power of 2), intializes values, and builds tree
 *  cmb: Associative operations for the seg tree
 *  build: Builds the corresponding segment tree
 *  pull: Updates the value at a node (cmb on both child nodes)
 *  upd: Updates the vales of idx with given value
 *  query: Range query between l and r inclusive (0 indexed)
 */

#include <bits/stdc++.h>
using namespace std;

template<class T>
struct SegTree {
	const T INIT{};
	int size; vector<T> seg;
	SegTree(int n, vector<T>&v) : size(1){
		while(size < n) size <<= 1;
		seg.assign(2*size+1, INIT); build(v);
	}
	T cmb(T a, T b){ 
		return a + b;
	}
	void build(vector<T>&a) { build(a, 0, 0, size); }
	void pull(int p){ seg[p] = cmb(seg[2*p+1], seg[2*p+2]); }
	void upd(int i, T v) { upd(i, v, 0, 0, size); }
	T query(int l, int r) { return query(l, r, 0, 0, size); }
	
	void build(vector<T>&a, int node, int left, int right){
		if (left == right){ if (left < a.size()) { seg[node] = a[left]; } return;}
		int mid = left + (right - left) / 2;
		build(a, node*2+1, left, mid); build(a, node*2+2, mid+1, right);
		pull(node);
	}
	void upd(int i, T v, int node, int left, int right) {
		if (left == right){ seg[node] = v; return; }
		int mid = left + (right - left) / 2;
		if (i <= mid){ upd(i,v,node*2+1, left, mid); }
		else { upd(i,v,node*2+2, mid+1, right); }
		pull(node);
	}
	T query(int l, int r, int node, int left, int right){
		if (l > right || r < left) return INIT;
		if (left >= l && right <= r) return seg[node];
		int mid = left + (right - left) / 2;
		return cmb(query(l, r, node*2+1, left, mid), query(l, r, node*2+2, mid+1, right));
	}
};

