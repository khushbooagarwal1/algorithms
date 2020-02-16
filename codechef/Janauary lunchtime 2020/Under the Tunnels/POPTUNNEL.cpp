#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
int main(){
	int T;
	cin >> T;

	for(int i = 0; i < T; i++){
		int N, K;
		cin >> N >> K;
		vector<int> dist(N, -1);
		dist[0] = 0;
		vector<string> tiles(N);
		for(int i = 0; i < N; i++){
			cin >> tiles[i];
		}
		queue<int> q;
		q.push(0);
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			for(int j = cur+1; j <= cur + K; j++){
				if(tiles[cur][j] == '1' && dist[j] == -1){
					q.push(j);
					dist[j] = dist[cur] + 1;
					if(j == N-1){
						break;
					}
				}
			}
			for(int j = cur-1; cur <= j + K; j--){
				if(tiles[cur][j] == '1' && dist[j] == -1){
					q.push(j);
					dist[j] = dist[cur] + 1;
				}
			}
			if(dist[N-1] != -1){
				break;
			}

		}
		cout << dist[N-1] << endl;
	}
}
