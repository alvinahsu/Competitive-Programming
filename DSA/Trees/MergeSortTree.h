#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e6;
vector<int>tree[5*N];
int a[N];
int n;

void build_tree( int cur , int l , int r )
{
	tree[cur].clear();
     if( l==r )
     {
     tree[cur].push_back( a[ l ] );
     return ;
     }
     int mid = l+(r-l)/2;
     build_tree(2*cur+1 , l , mid ); // Build left tree 
     build_tree(2*cur+2 , mid+1 , r ); // Build right tree
     merge(tree[2*cur+1].begin(), tree[2*cur+1].end(),
     	    tree[2*cur+2].begin(), tree[2*cur+2].end(),
     	    back_inserter(tree[cur])); //Merging the two sorted arrays
}
 
long long query( int cur, int l, int r, int x, int y, int k, bool less)
{
       if( r < x || l > y )
      {
               return 0; //out of range
      }
      if( x<=l && r<=y )
      {
              //Binary search over the current sorted vector to find elements smaller than K
      		if (less) {
              return lower_bound(tree[cur].begin(),tree[cur].end(),k)-tree[cur].begin();
      		}
          	else {
          		int leave = (upper_bound(tree[cur].begin(),tree[cur].end(),k)-tree[cur].begin());
          		return (int)tree[cur].size() - leave;
          	}
      }
      int mid=l+(r-l)/2;
     return query(2*cur+1,l,mid,x,y,k,less)+query(2*cur+2,mid+1,r,x,y,k,less);
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		build_tree(0, 0, n-1);
		long long ans = 0;
		for (int i = n-1; i >= 0; i--){
			int placeFirst = query(0, 0, n-1, 0, i-1, a[i], true);
			int placeLast = query(0, 0, n-1, 0, i-1, a[i], false);
			ans += min(placeFirst, placeLast);
		}
		cout << ans << '\n';
	}
	
	return 0;
}