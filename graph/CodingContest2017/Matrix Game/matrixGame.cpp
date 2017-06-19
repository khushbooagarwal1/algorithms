#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int g[51][51],visited[51][51],n,m;

void fill(int i,int j){
    //already done
    if(visited[i][j] == 1)
        return;
        
    //start node is always border node
    visited[i][j] = 1;
    //check which nodes are reachable to the particular border node
    if(i != 0 && g[i - 1][j] >= g[i][j])
        fill(i - 1, j);
    if(i != n - 1 && g[i + 1][j] >= g[i][j])
        fill(i + 1, j);

    if(j != 0 && g[i][j - 1] >= g[i][j])
        fill(i, j - 1);
    if(j != m - 1 && g[i][j + 1] >= g[i][j])
        fill(i, j + 1);
}

int main() {

    int t;
    cin >> t;
    while(t-- > 0){
        cin >> n >> m;

        for(int i = 0;i < n; i++)
        {
            for(int j = 0; j < m; j++){
                cin >> g[i][j];
                visited[i][j] = 0;
            }
        }
        //call the function for each border node
        for(int i = 0; i < m; i++)
            fill(0,i);
        for(int i = 0; i < m; i++)
            fill(n - 1,i);
        for(int i = 0; i < n; i++)
            fill(i,0);
        for(int i = 0; i < n; i++)
            fill(i, m - 1);
        //result
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0 ; j < m; j++)
                if(visited[i][j])
                    ans++;
        cout << ans << endl;
    }

}
