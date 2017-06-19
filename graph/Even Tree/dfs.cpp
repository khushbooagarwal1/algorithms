/* Simple Idea is to traverse the tree(dfs) and check for those nodes who has a subtree with odd number of child. Or find a node with odd number of subtree,(so if we include that node, there will be even nodes in that subtree) Remove the edge of that subtree from its ancestor. */


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
map< int, vector< int > > adj;
int ans;
int flag = 0;
void dfs(int u, vector< int >& visited){
    visited[u] = 0;    //initially no child has been explored, but node has been
    for(vector< int >::iterator it = adj[u].begin(); it != adj[u].end(); ){
        if(visited[*it] == -1){
            dfs(*it, visited);
            //if we found the subtree with odd number of children
            if(flag == 1){
                //remove then edge, no need to remove the edge(*it->u), *it will never be visited again
                adj[u].erase(it);   //iterator will be incremented implicitly due to erase. avoid erase in for loop
                //result
                ans++;
                flag = 0;
                //number of children won't be incremented as edge has been removed.
            }
            else{
                //store number of children
                visited[u] += visited[*it]+1;
                it++;
                
            }
        }
        else{
            it++;
        }
    }
    //if node has odd number of children in subtree, EUREKA..!!
    if(visited[u] != 0 && visited[u]%2){
        flag = 1;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin >> n >> m;
    //tree input
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
     //visited will store number of children for those nodes whose children has been explored.
    //for leaf node, visited value will be zero, and for root, it will b total nuber of nodes in its subtrees.
    vector< int > visited(n, -1);
    ans = 0;
    for(int i = 0; i < n; i++){
        if(visited[i] == -1){
            dfs(i, visited);
        }
    }
    cout << ans;
    return 0;
}
