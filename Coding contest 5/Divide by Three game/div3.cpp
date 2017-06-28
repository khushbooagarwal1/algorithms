#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void divide3(long int a, long int& count){
    if(a == 1){
        return;
    }
    //one decrement operation
    if(a == 2){
        count++;
        return;
    }
    //decrement by one operation and then divide by 3
    if(a % 3 == 1){
        count++;
        divide3(a - 1, count);
    }
    //increment by one operation and then divide by 3
    if(a % 3 == 2){
        count++;
        divide3(a + 1, count);
    }
    //divide by 3 operation
    if(a% 3 == 0){
        count++;
        divide3(a / 3, count);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    for(; t > 0; t--){
        long int a;
        cin >> a;
        long int count = 0;
        divide3(a, count);
        cout << count << endl;
    }
    return 0;
}
