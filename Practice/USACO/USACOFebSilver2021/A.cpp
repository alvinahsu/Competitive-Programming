/*
*  File: USACOFebSilver2021A
*  Author: Alvin Hsu
*  Date: 08/28/2023 19:22:54
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

//only need to check surrounding cows at placement [i,j] and cow itself
//if reach three, need to place at remaining
int DIRX[] = {0,0,-1,1};
int DIRY[] = {1,-1,0,0};
int g[1010][1010];

int OFFSET = 5;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(g, 0, sizeof g);
	int n;
	cin >> n;
	
	auto cnt = [&](int x, int y){
		int have = 0;
		for (int j = 0; j < 4; j++){
			int dx = x + DIRX[j];
			int dy = y + DIRY[j];
			have += g[dx][dy];
		}
		return have;	
	};
	
	auto check = [&](int x, int y){
		
	};
	for (int i = 0; i < n; i++){
		int x,y;
		cin >> x >> y;
		x += OFFSET;
		y += OFFSET;
		
	}
	return 0;
}
