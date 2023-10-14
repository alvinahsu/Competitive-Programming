#include <bits/stdc++.h>
using namespace std;

bool check(string &n, long long k) {
    long long rem = 0;
    for (auto i : n)
        rem = ((rem * 10) + i - '0') % k;
    return rem == 0;
}