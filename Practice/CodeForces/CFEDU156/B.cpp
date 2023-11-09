/*
*  File: CFEDU156B
*  Author: Alvin Hsu
*  Date: 11/08/2023 15:07:00
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	auto getDist = [&](int x1, int y1, int x2, int y2){
		return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	};
	while(t--){
		int px,py,ax,ay,bx,by;
		cin >> px >> py >> ax >> ay >> bx >> by;
		double d1 = max(getDist(0,0,ax,ay), getDist(px,py,ax,ay));
		double d2 = max(getDist(0,0,bx,by), getDist(px,py,bx,by));
		double d3 = max({getDist(ax,ay,bx,by) / 2, getDist(0,0,ax,ay), getDist(px,py,bx,by)});
		double d4 = max({getDist(ax,ay,bx,by) / 2, getDist(0,0,bx,by), getDist(px,py,ax,ay)});
		
		cout << fixed << setprecision(15) << min({d1,d2,d3,d4}) << '\n';
	}
	return 0;
}
