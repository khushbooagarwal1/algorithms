#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector< int > A = {1, 2,3,4,5};
    int n = A.size();
    int m = 3;
    vector< int > distance;
    int l = -1;
    for(int r = 0; r < n; r++){
        if(A[r] % 2 == 1){
            distance.push_back(r - l -1);
            l = r;
        }
    }
    int res = 0;
    distance.push_back(n - l - 1);
    int s = distance.size();
    
    if(m > 0){
        for(int i = 0; i < s - m; i++){
            res += ((distance[i] + 1) * (distance[i+m] + 1));
        }
    }
    else{
        for(int i = 0; i < s; i++){
            res += (((distance[i] + 1) * distance[i]) / 2);
        }
    }
    cout << res << endl;
    return 0;
}
