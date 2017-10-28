#include <bits/stdc++.h>

using namespace std;
typedef struct adjList{
    int node;
    adjList* next;
} adjList;

typedef struct Graph{
    adjList* head;
}Graph;


void addEdge(Graph *g, int u, int v){
    adjList* newNode = new  adjList;
    newNode->node = v;
    newNode->next = NULL;
    adjList* temp = g[u].head;
    if(temp == NULL){
        g[u].head = newNode;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
Graph* newGraph(int n){
    Graph* graph = new Graph[n];
    for(int i = 0; i < n; i++){
        graph[i].head = NULL;
    }
    return graph;
}
bool isBipartiteUtil(Graph* G, int src, int color[], int c){
    color[src] = c;
    adjList* temp = G[src].head;
    while(temp != NULL){
        
        cout << src + 1 <<" "<< temp->node + 1 << endl;
        if(color[temp->node] == -1){
            bool b = isBipartiteUtil(G, temp->node, color, !c);
            if(b == false){
                return false;
            }
        }
        if(color[temp->node] == color[src]){
            return false;
        }
        temp = temp->next;
    }
    return true;
}
bool isBipartite(Graph* g, int n){
    int color[n];
    for (int i = 0; i < n; ++i)
        color[i] = -1;
 
    // This code is to handle disconnected graoh
    for (int i = 0; i < n; i++)
      if (color[i] == -1)
        if (isBipartiteUtil(g, i, color, 0) == false)
           return false;
 
     return true;
}
int main(){
    int n, m;
    cin >> n >> m;
    Graph* g = newGraph(n);
    for(int a1 = 0; a1 < m; a1++){
        int u;
        int v;
        cin >> u >> v;
        addEdge(g, u-1, v-1);
    }
    
    cout << isBipartite(g, n) << endl;
    for(int a1 = 0; a1 < n; a1++){
        adjList* temp = g[a1].head;
        cout << a1 +1 << " -> ";
        while(temp != NULL){
            cout << temp->node + 1 << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    return 0;
}
