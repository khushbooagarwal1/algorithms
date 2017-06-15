#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#define MAX 300000009
using namespace std;
struct comp
{
    bool operator() (const pair< int, long int >& p1, const pair< int, long int >& p2)
    {
        return p1.second > p2.second;
    }
};
 
void dijkstra(map<int, vector< pair< int, int > > >& adj, int s, int n){
    priority_queue< pair< int, long int >, vector< pair< int, long int > >, comp  >pq;
    vector< long int > dist(n, MAX);
    dist[s] = 0;
    vector< long int > proc(n, 0);
    pq.push(make_pair(s, 0));
    while(!pq.empty()){
        int node = pq.top().first;
        int weight = pq.top().second;
        if(proc[node] == 0){
            vector< pair< int, int > >::iterator it;
            for(it = adj[node].begin(); it != adj[node].end(); it++){
                if(dist[node] + (*it).second < dist[(*it).first]){
                    dist[(*it).first] = dist[node] + (*it).second;
                    pq.push(make_pair((*it).first, dist[(*it).first]));
                }
            }
            proc[node] = 1;
        }
        pq.pop();
    }
    for(int i = 0; i < n; i++){
        if(dist[i] == MAX){
            dist[i] = -1;
        }
        if(i != s){
            if(i == n-1){
               
                cout << dist[i] << endl;
            }
            else{
                cout << dist[i] << " ";
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
        map<int, vector< pair< int, int > > > adj;
        for(int i = 0; i < m; i++){
            int temp1, temp2, temp3;;
            cin >> temp1 >> temp2 >> temp3;
            adj[temp1-1].push_back(make_pair(temp2-1, temp3));
            adj[temp2-1].push_back(make_pair(temp1-1, temp3));
        }
        int s;
        cin >> s;
        dijkstra(adj, s-1, n);
    }
    return 0;
}
