#include <bits/stdc++.h>
using namespace std;

//O((N+Q)*sqrt(N))
int block_size = 101;
const int N = 2e5;
struct Query {
    int l, r, idx;
    bool operator<(Query other) const {
        if(l / block_size != other.l / block_size)
            return (l/block_size) < (other.l/block_size);
        return r < other.r;
    }
} Q[N];


vector<Query> queries;
vector<int> answers;

void remove(int i) {
    
}

void add(int i) {
    
}
int get_answer() {
    
}

void mos () {
    //resize answer
    //sort queries
    int l = 0;
    int r = -1;
    for (Query q : queries) {
        while (l > q.l) add(--l);
        while (r < q.r) add(++r);
        while (l < q.l) remove(l++);
        while (r > q.r) remove(r--);
        answers[q.idx] = get_answer();
    }
}