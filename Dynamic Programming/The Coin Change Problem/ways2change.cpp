#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long coinChange(int N, int M, vector< int >& C)
{
    vector< vector< long > > coin(N+1, vector< long >(M, 0));
    //1 way to get change for Rs 0
    for(int i = 0; i < M; i++)
        coin[0][i] = 1;
    
    for(int i = 1; i < N+1; i++)
    {
        for(int j = 0; j < M; j++)
        {
            //if coin denomination is less than change required, we can get the change using that coin
            if(i >= C[j]){
                coin[i][j] = coin[i - C[j]][j];
            }
            else{
                //change not possible
                coin[i][j] = 0;
            }
            //get change using previous coins of lesser denomination
            if(j > 0)
                coin[i][j] += coin[i][j-1];
        }
    }
    return coin[N][M-1];
}

int main() {
    int N, M;
    cin >> N >> M;
    vector< int > C(M);
    for(int i = 0; i < M; i++)
    {
        cin >> C[i];
    }
    cout << coinChange(N, M, C);
    return 0;
}
