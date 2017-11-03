#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int n = 6;
set< string > op;
void find_subsequence(string path, int start, int end, int pos, string ans){
    int count = 0;
    if(n == start or start < 0){
        return;
    }
    if(pos == path.size()){
        if(start == end){
            op.insert(ans);
        }
    }
    else{
        if(start == end){
            op.insert(ans);
        }
        if(path[pos] == 'L'){
            find_subsequence(path, start-1, end, pos+1, ans+"L");
        }
        if(path[pos] == 'R'){
            find_subsequence(path, start+1, end, pos+1, ans + "R");
        }
        find_subsequence(path, start, end, pos+1, ans);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    string input = "RRLRLR";
    int start = 1, end= 2;
     find_subsequence(input, start, end, 0 , "");
    cout<< op.size();
    return 0;
}
