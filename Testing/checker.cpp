#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define dbg(...)
#endif

int main(int argc, char * argv[]){
    ifstream fin("input_file", ifstream::in);
    ifstream ans("myAnswer", ifstream::in);
    ifstream cor("correctAnswer", ifstream::in);
        
    //read input from fin
    
    //1 correct, 0 incorrect
    auto readAns = [&](ifstream &fin) -> int {
        //check answer against the input
        
        
        
        return 1;
    };
    
    int myAnswer = readAns(ans);
    int correctAnswer = readAns(cor);
    
    if (!(correctAnswer == 1 && myAnswer == 1)){
        cout << "Wrong answer" << endl;
        return -1;
    }
    return 0;
}