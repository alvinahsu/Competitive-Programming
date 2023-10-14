#include <bits/stdc++.h>
using namespace std;

//MAKE SURE TO MEMSET DP

// digit sum
long long dp[20][200][2][2];
long long solve(string num, int i, int sum, bool tight, bool lz){
  if (i == num.size()){
    return sum;
  }
  auto &ret = dp[i][sum][tight][lz];
  if (ret != -1) return ret;
  ret = 0;
  int ub = tight ? num[i]-'0' : 9;
  for (int dig = 0; dig <= ub; dig++){
    ret += solve(num, i+1, sum+dig, tight&(dig==ub), lz&(!dig));
  }
  return ret;
}

// // digits add to sum
// int dp[101][181][2];
// int solve(string num, int i, int sum, bool tight){
//   if (sum < 0) return 0;
//   if (i == num.size()){
//     return !sum;
//   }
  
//   auto &ret = dp[i][sum][tight];
//   if (ret != -1) return ret;
//   ret = 0;
//   int ub = tight ? num[i]-'0' : 9;
//   for (int dig = 0; dig <= ub; dig++){
//     ret += solve(num, i+1, sum-dig, tight&(dig==ub));
//   }
//   return ret;
// }

// // odd,even,odd,even,... numbers 
// long long dp[50][2][2][2];
// long long solve(string num, int i, bool tight, bool lz, bool odd){
//   if (i == num.size()){
//     return 1;
//   }
//   auto &ret = dp[i][tight][lz][odd];
//   if (ret != -1) return ret;
//   ret = 0;
//   int ub = tight ? num[i]-'0' : 9;
//   if (odd && lz){
//     ret += solve(num, i+1, 0, 1, 1);
//   }
//   for (int dig = odd; dig <= ub; dig+=2){
//     ret += solve(num, i+1, tight&(dig==ub), 0, odd^1);
//   }
//   return ret;
// }
