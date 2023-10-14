#include <bits/stdc++.h>
using namespace std;

int n = 0, m = 0;
//O(N log N + N log M)
void InvGraph(){    
    vector<set<int>> adj(n+1);
    set<int> toremove;
    queue<int> bfs;
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    vector<int> todo;
    //mark the nodes that we need to visit/remove
    for(int i = 1; i <= n; i++) {
        toremove.insert(i);
    }
    int ccs = 0;
    for(int i = 1; i <= n; i++) {
        //if we haven't removed
        if(toremove.count(i)) {
            //run bfs
            bfs.push(i);
            ccs++;
            toremove.erase(i);
            while(bfs.size()) {
                int x = bfs.front();
                bfs.pop();
                todo.clear();
                //check j not adjacent to x
                for(int j : toremove) {
                    if(!adj[x].count(j)) { 
                        todo.push_back(j);
                    }
                }
                //push all next nodes to bfs queue
                for(int j : todo) {
                    toremove.erase(j), bfs.push(j);
                }   
            }
        }
    }
}