/*    /c\
    a<   >b
*/    \d/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    vector< vector< int > > mat(n, vector< int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }
    long long int ans = 0;
    //chhose 'a'
    for(int i = 0; i < n; i++){
    //chhose b
        for(int j = i + 1; j < n; j++){
            int count = 0;
            //check for all such numbers(count) that are connected to both 'a' and 'b'
            for(int k = 0; k < n; k++){
                if(mat[i][k] && mat[j][k]){
                    count++;
                }
            }
           //chhose two number c, d out of all count
            ans += ( count*(count - 1) )/ 2;
        }
    }
    //clockwise and anticlockwise are same for choice of c, d;
    cout << ans/2 << endl;

    return 0;
}
