#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define dbg(...)
#endif

// https://ali-ibrahim137.github.io/competitive/programming/2020/08/23/Stress-Testing.html

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

/* --- GENERATE UNIQUE ARRAY --- */
// int main(int argc, char* argv[]) {
//     srand(atoi(argv[1]));
//     int n = rand(2, 10);
//     printf("%d\n", n);
//     set<int> used;
//     for(int i = 0; i < n; ++i) {
//         int x;
//         do {
//             x = rand(1, 10);
//         } while(used.count(x));
//         printf("%d ", x);
//         used.insert(x);
//     }
//     puts("");
// }

/* --- GENERATE RANDOM ARRAY --- */
int main(int argc, char* argv[]){
    srand(atoi(argv[1]));
    puts("1");
    int n = rand(1, 20);
    printf("%d\n", n);
    for(int i = 0; i < n; i++){
        int x = rand(-1e8, 1e8);
        printf("%d ", x);
    }
    puts("");
}

/* --- GENERATE TREE --- */
// int main(int argc, char* argv[]) {
//     srand(atoi(argv[1]));
//     int n = rand(2, 20);
//     printf("%d\n", n);
//     vector<pair<int,int>> edges;
//     for(int i = 2; i <= n; ++i) {
//         edges.emplace_back(rand(1, i - 1), i);
//     }
    
//     vector<int> perm(n + 1); // re-naming vertices
//     for(int i = 1; i <= n; ++i) {
//         perm[i] = i;
//     }
//     random_shuffle(perm.begin() + 1, perm.end());
    
//     random_shuffle(edges.begin(), edges.end()); // random order of edges
    
//     for(pair<int, int> edge : edges) {
//         int a = edge.first, b = edge.second;
//         if(rand() % 2) {
//             swap(a, b); // random order of two vertices
//         }
//         printf("%d %d\n", perm[a], perm[b]);
//     }
// }

/* --- GENERATE RANDOM NUMBER --- */
// int main(int argc, char* argv[]){
//     srand(atoi(argv[1]));
//     int n = rand(1, 100);
//     printf("%d\n", n);
//     puts("");
// }