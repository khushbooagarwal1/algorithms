#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    for(; t > 0; t--){
        int n;
        cin >> n;
        vector< int > A(n);
        vector< int > B(n);
        for(int i = 0; i < n; i++){
            cin >> A[i];
        }
        for(int i = 0; i < n; i++){
            cin >> B[i];
        }
        //start from minimum one
        int temp = min(A[0], B[0]); 
        int flag = 0;
        for(int i = 1; i < n; i++){
            //check if current minimum is less than last minimum, then pick the number
            if(min(A[i], B[i]) >= temp){
                temp = min(A[i], B[i]);
            }
            else if(max(A[i], B[i]) >= temp){
                //else if other one is less than last minimum, pick that
                temp = max(A[i], B[i]);
            }
            else{
                //nondecreasing sequence not possible
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }
    return 0;
}
