#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
void bfs(map<int, vector< int > > adj, int s, int n){
    vector< int > visited(n, 0);
    vector< int > dist(n, -1);
    queue< pair< int,int > > q;
    q.push(make_pair(s, 0));
    visited[s] = 1;
    dist[s] = 0;
    while(!q.empty()){
        int u = q.front().first;
        int pos = q.front().second; 
        q.pop();
        for(int i = 0 ; i < adj[u].size(); i++){
            if(visited[adj[u][i]] == 0){
                q.push(make_pair(adj[u][i], pos+1));
                visited[adj[u][i]] = 1;
                dist[adj[u][i]] = 6* (pos+1);
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(i != s){
            if(i == n-1){
                cout << dist[i]<<endl;
            }
            else{
                cout << dist[i]<< " ";
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    cin >> t;
    for(; t > 0; t--){
        int n, m;
        cin >> n >> m;
        map<int, vector< int > > adj;
        for(int i = 0; i < m; i++){
            int temp1, temp2;
            cin >> temp1 >> temp2;
            adj[temp1-1].push_back(temp2-1);
            adj[temp2-1].push_back(temp1-1);
        }
        int s;
        cin >> s;
        bfs(adj, s-1, n);
    }
    return 0;
}
