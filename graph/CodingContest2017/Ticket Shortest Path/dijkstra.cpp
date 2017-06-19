#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <algorithm>
#define MAX 1500001
using namespace std;


//dijkstra using set
vector<int> dijkstra(int n, map< int, vector< pair< int, int > > > &Graph, int source ) {
    vector<int> d(n + 1, MAX);
    d[source] = 0;
    set< pair<  int,int > > q;
    q.insert(make_pair(0LL,source));
    while(!q.empty()) {
        pair< int, int > cur = *q.begin();
        q.erase(q.begin());
        int u = cur.second;
        int w = cur.first;
        if(d[u] == w) {
            for(int i = 0;i < Graph[u].size();i++) {
                int v = Graph[u][i].first;
                if(w + Graph[u][i].second < d[v]) {
                    d[v] = Graph[u][i].second + w;
                    q.insert(make_pair(d[v],v));
                }
            }
        }

    }
    return d;
}


int main() {
    int t; cin>>t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        vector< pair<int,int> > edges(m);
        vector< pair<int,int> > weights(m);
        map< int,  vector< pair< int, int > > > Graph;
        for(int i = 0;i < m;i++) {
            cin >> edges[i].first >> edges[i].second;
            cin >> weights[i].first >> weights[i].second;
            //store roadways weight only
            Graph[edges[i].first].push_back(make_pair(edges[i].second, weights[i].first));
            Graph[edges[i].second].push_back(make_pair(edges[i].first ,weights[i].first));
            
        }
        int s,d; 
        cin >> s >> d;
        //distance from source to all node
        vector<int> d1 = dijkstra(n,Graph,s);
        //distance from destination to all node
        vector<int> d2 = dijkstra(n,Graph,d);
        
        //to reach destination using roadways only
        int ans = d1[d];
        
        for(int i = 0;i < m;i++) {
            //for edge (m, n), roadcost[source->m] + roadcost[n->destination] + railcost[m->n]
            ans = min(ans, d1[edges[i].first] + d2[edges[i].second] + weights[i].second);
            //for edge (m, n), roadcost[destination->m] + roadcost[n->source] + railcost[m->n]
            ans = min(ans, d1[edges[i].second] + d2[edges[i].first] + weights[i].second);
        }
        cout << ans << endl;
    }
}
