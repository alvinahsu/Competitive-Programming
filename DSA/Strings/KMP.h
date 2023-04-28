#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> lps(n);
    for (int i = 1; i < n; i++) {
        int j = lps[i-1];
        while (j > 0 && s[i] != s[j])
            j = lps[j-1];
        if (s[i] == s[j])
            j++;
        lps[i] = j;
    }
    return lps;
}

vector<int>ans;
// returns matches in vector ans in 0-indexed
void kmp(vector<int> lps, string s, string p) {
    int psz = p.size(), sz = s.size();
    int j = 0;
    for(int i = 0; i < sz; i++) {
        //while mistmatched
        while(j >= 0 && p[j] != s[i])
            //go to previous matching
            if(j >= 1) j = lps[j - 1];
            else j = -1;
        j++;
        if(j == psz) {
            j = lps[j - 1];
            // pattern found in string s at position i-psz+1
            ans.push_back(i - psz + 1);
        }
    }
}