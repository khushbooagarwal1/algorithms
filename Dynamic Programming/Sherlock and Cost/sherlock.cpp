#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int test;
    cin >> test;
    for(int i = 0; i < test; i++){
        int N, temp;
        cin >> N;
        vector< int > B;
        B.reserve(N);
        for(int j = 0; j < N; j++){
            cin >> temp;
            B.push_back(temp);
        }
        //S would b maximum only if we choose A to be either 1 or B
        vector< pair < int, int > > res(N + 1, make_pair(0, 0));
        for(int k = 1; k < N; k++){
            //if we choose 1, (if previous was 1, diff = 1-1 = 0) (if previous was B. diff = B-1)
            res[k].first = max(res[k-1].first, res[k-1].second + B[k-1] - 1);
            //if we choode Bk, (if previous was Bk-1, diff = B_k - B_(k-1)) (if previous was zero, diff = Bk - 1)
            res[k].second = max(res[k-1].second + abs(B[k] - B[k-1]), res[k-1].first + B[k] - 1);
        }
        cout << max(res[N-1].first, res[N-1].second) << endl;
    }
    return 0;
}
