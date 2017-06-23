#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define INF 1000000000
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, k;
    cin >> n >> k;
    vector< long int > num(n);
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    #always pick a sorted block as it will contain minimu distance between maximum and minimum element
    sort(num.begin(), num.end());
    long int min = INF
    
    //check for the last(maiximum) and first(minimum) element
    for(int i = 0; i < n - k + 1; i++){
        if(num[i+k-1] - num[i] < min){
            min = num[i+k-1] - num[i];
        }
    }
    cout << min << endl;
    return 0;
}
