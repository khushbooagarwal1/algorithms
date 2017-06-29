#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int N;
    long int temp;
    cin >> N;
    vector< long int > student(N);
    student.reserve(N);
    for(int i = 0; i < N; i++){
        cin >> student[i];
    }
    
    vector< long int > result(N, 1);
    //traverse in one direction, increase candy count to following high ranked student
    for(int j = 1; j < N; j++){
        if(student[j - 1] < student[j]){
            result[j] = result[j - 1] + 1 ;
        }
    }
    long int sum = result[N-1];
    
    //traverse in other direction, increase candy count to preceding haig ranked student
    for(int j = N-1; j > 0; j--){
        if(student[j - 1] > student[j] && result[j-1] <= result[j]){
            result[j - 1] = result[j] + 1 ;
        }
        sum += result[j -1];
    }
    cout << sum;
    return 0;
}
