#include<iostream>
#include<vector>

using namespace std;

int main() {

	int C, F;
	cin >> C >> F;
	int INF = 1000000000;
	vector<vector<int> > graph(C, vector<int>(C, INF));

	int dist = -1;
	for(int i = 0; i < F; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a-1][b-1] = c;
		graph[b-1][a-1] = c;
	}

	for(int source = 0; source < C; source++){
		for(int dest = 0; dest < C; dest++){
			if(source != dest){
				for(int intermediate = 0; intermediate < C; intermediate++){
					if(intermediate != source && dest != intermediate){
						if(graph[source][intermediate] + graph[intermediate][dest] < graph[source][dest]){
							graph[source][dest] = graph[source][intermediate] + graph[intermediate][dest];
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < C; ++i)
	{
		for(int j = 0; j < C; j++){
			
			if(dist < graph[i][j] && graph[i][j] != INF) {
				dist = graph[i][j];
			}
		}
		/* code */
	}
	cout << dist;

	return 0;
}
