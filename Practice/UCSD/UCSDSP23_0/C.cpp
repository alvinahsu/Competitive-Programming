/*
*  File: UCSDSP23_0C
*  Author: Alvin Hsu
*  Date: 11/04/2023 09:24:55
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

struct Car {
	Car * rear;
	Car * front;
	int num;
	
	Car(int n) {
		num = n;
		rear = nullptr;
		front = nullptr;
	}	
};
//front of car y to read of car x
void connect(Car * x, Car * y){
	y->front = x;
	x->rear = y;
}

//y is rear of x
void disconnect(Car * x, Car * y){
	x->rear = nullptr;
	y->front = nullptr;
}

void getCars(Car * curr){
	while(curr -> rear != nullptr){
		curr = curr -> rear;
	}
	vector<int> ans;
	while(curr != nullptr){
		ans.push_back(curr->num);
		curr = curr -> front;
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size();
	for (auto &a : ans){
		cout << " " << a;
	}
	cout << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,q;
	cin >> n >> q;
	vector<Car*> v(n+1);
	for (int i = 1; i <= n; i++){
		v[i] = new Car(i);
	}
	while(q--){
		int t;
		cin >> t;
		if (t == 1){
			int x,y;
			cin >> x >> y;
			connect(v[x], v[y]);
		}
		else if (t == 2){
			int x,y;
			cin >> x >> y;
			disconnect(v[x], v[y]);
		}
		else {
			int x;
			cin >> x;
			getCars(v[x]);
		}
	}
	return 0;	
}
