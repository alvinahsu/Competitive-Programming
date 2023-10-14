#include <bits/stdc++.h>
using namespace std;

struct Congruence {
    long long a, m;
};
long long power(long long a, long long m){
    long long ans = 1, b = m-2;
    while(b){
        if (b&1) {
            (ans *= a) %= m;
        }
        b >>= 1;
        (a *= a) %= m;
    }
    return ans;
}

long long inv(long long a, long long m){
    if (gcd(a,m) != 1) {
        return -1;
    }
    return power(a, m);
}


long long chinese_remainder_theorem(vector<Congruence> const& congruences) {
    long long M = 1;
    for (auto const& congruence : congruences) {
        M *= congruence.m;
    }

    long long solution = 0;
    for (auto const& congruence : congruences) {
        long long a_i = congruence.a;
        long long M_i = M / congruence.m;
        long long N_i = inv(M_i, congruence.m);
        solution = (solution + a_i * M_i % M * N_i) % M;
    }
    return solution;
}