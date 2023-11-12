/*
*  File: USACOUSOpenSilver21A
*  Author: Alvin Hsu
*  Date: 07/30/2023 14:00:47
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

struct Move {
	char c;
	int i,j;	
};

int DIRX[4] = {0,0,1,-1};
int DIRY[4] = {1,-1,0,0};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//dfs the maze
	int n;
	cin >> n;
	vector<vector<Move>> v(n, vector<Move>(n));
	int si,sj;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j+=3){
			if (s[j] == 'B'){
				si = i, sj = j/3;
			}
			v[i][j/3] = {s[j],s[j+1]-'0'-1,s[j+2]-'0'-1};
		}
	}
	int ans = 0;
	auto check = [&](vector<vector<char>> board){
		for (int i = 0; i < 3; i++){
			string s, ss;
			for (int j = 0; j < 3; j++){
				s += board[i][j];
				ss += board[j][i];
			}
			if (s == "MOO" || s == "OOM" || ss ==  "MOO" || ss == "OOM") return true;
		}
		string s = to_string(board[0][0]) + board[1][1] + board[2][2];
		string ss = to_string(board[0][2]) + board[1][1] + board[2][0];
		if (s == "MOO" || s == "OOM" || ss ==  "MOO" || ss == "OOM") return true;
		return false;
	};
	vector<vector<int>> vis(n, vector<int>(3));
	vector<vector<char>> board(3, vector<char>(3, '.'));
	function<void(int,int)> dfs = [&](int i, int j){
		auto m = v[i][j];
		if (m.c == '#') return;
		bool hasMove = m.c == 'O' || m.c == 'M';
		if (hasMove){
			dbg(m.i,m.j);
			if (board[m.i][m.j] == '.'){
				board[m.i][m.j] = m.c;
			}
		}
		bool win = check(board);
		if (win) {
			
		}
		// dbg(board);
		ans += win;
		for (int d = 0; d < 4; d++){
			int ni = i + DIRY[d];
			int nj = j + DIRX[d];
			if (ni >= 0 && ni < n && nj >= 0 && nj < n){
				dfs(ni,nj);
			}
		}	
		if (hasMove){
			board[m.i][m.j] = '.';
		}
		vis[i][j] = 0;
	};
	dfs(si,sj);
	cout << ans << '\n';
	return 0;
}
