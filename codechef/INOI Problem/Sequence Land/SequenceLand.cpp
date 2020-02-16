#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

int main(){

	int n, K;
	cin >> n >> K;

	vector<map<int, int> > input;
	vector<vector<int> > graph(n);

	for(int i =0; i < n; i++) {
		int len;
		cin >> len;
		map<int, int> temp;
		for(int j = 0; j < len; j++){
			int id;
			cin >> id;
			temp[id] = 1;
		}
		input.push_back(temp);
	}
	for(int i = 0; i < n; i++) {
		if(input[i].size() >= K) {
			for(int j = i+1; j < n; j++){
				int count = 0;
				for(map<int, int>::iterator it = input[j].begin(); it != input[j].end() && count != K; it++){
					if(input[i][it->first] == 1){
						count++;
					}	
				}
				if(count == K){
					graph[j].push_back(i);
					graph[i].push_back(j);
				}
			}
		}
	}
	queue<int> q;
	std::vector<int> visited(n, 0);
	visited[0] = 1;
	q.push(0);
	int result = 1;
	while(!q.empty()){
		int elem = q.front();
		q.pop();
		for(int i = 0; i != graph[elem].size(); i++){
			if(visited[graph[elem][i]] == 0) {
				q.push(graph[elem][i]);
				visited[graph[elem][i]] = 1;
				result++;
			}
		}
	}

	cout << result;


	return 0;
}
