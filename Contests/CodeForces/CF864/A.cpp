/*
*  File: CF864A
*  Author: Alvin Hsu
*  Date: 08/04/2023 21:59:37
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

int DIRX[4] = {0,0,-1,1};
int DIRY[4] = {1,-1,0,0};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int blockEnd = 4, blockStart = 4;
		for (int i = 0; i < 4; i++){
			int newX2 = x2 + DIRX[i];
			int newY2 = y2 + DIRY[i];
			if (newX2 <= 0 || newX2 > n || newY2 <= 0 || newY2 > m) {
				blockEnd--;
			}
			int newX1 = x1 + DIRX[i];
			int newY1 = y1 + DIRY[i];
			if (newX1 <= 0 || newX1 > n || newY1 <= 0 || newY1 > m) {
				blockStart--;
			}
			
		}
		cout << min(blockEnd, blockStart) << '\n';
	}
	return 0;	
}
