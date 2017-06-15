#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
struct comp{
    bool operator()(const pair<int, pair< int, int > > & p1, const pair<int, pair< int, int > >& p2){
        return p1.first > p2.first;
    }
};
int find(int a, vector< int > & parent){
    if(parent[a] == -1){
        return a;
    }
    else{
        return find(parent[a], parent);
    }
}
void union_edge(pair< int, int > edge, vector< int > & parent){
    int x = find(edge.first, parent);
    
    int y = find(edge.second, parent);
    parent[x] = y;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin >> n >> m;
    priority_queue< pair<int, pair< int, int > >, vector< pair<int, pair< int, int > > >, comp > pq;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        pq.push(make_pair(c, make_pair(a-1, b-1)));
    }
    int res = 0;
    vector< int > parent(n, -1);
    while(!pq.empty()){
        int weight = pq.top().first;
        pair< int, int > edge = pq.top().second;
        if(find(edge.first, parent) != find(edge.second, parent)){
            union_edge(edge, parent);
            res += weight;
        }
        pq.pop();
    }
    cout << res;
    return 0;
}
