#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m, temp;
    cin >> n >> m;
    vector< int > s1(n);
    vector< int > s2(m);
    vector< int > result;
    result.reserve(max(m, n));
    for(int i = 0; i < n; i++){
        cin >> s1[i];
    }
    for(int i = 0; i < m; i++){
        cin >> s2[i];
    }
    //to store subsequnece length
    vector< vector< int > > mat(n+1, vector<int>(m+1, 0));
    //to get back characters 
    vector< vector< int > > mat2(n+1, vector<int>(m+1, 0));
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i - 1] == s2[j - 1]){
                mat[i][j] = mat[i-1][j-1] + 1;
                mat2[i][j] = 0;     //diagonal value derived
            }
            else{
                if(mat[i][j-1] > mat[i-1][j])
                {
                    mat[i][j] =  mat[i][j-1];
                    mat2[i][j] = 1;     //left value derived
                }
                else
                {
                    mat[i][j] = mat[i-1][j];    //right value derived
                    mat2[i][j] = -1;
                }
            }
        }
    }
    for(int i = n, j = m; j > 0 && i > 0;){
        //get result..only if match
        if(mat2[i][j] == 0){
            result.push_back(s1[i-1]);
            i--;
            j--;
        }
        else if(mat2[i][j] == 1){
            j--;    //left
        }
        else{
            i--;    //right
        }
    }
    for(int i = result.size() - 1; i >= 0; i--){
        if(i == 0){
            cout << result[i] << endl;
        }
        else{
            cout << result[i] << " ";
        }
    }
    return 0;
}
