#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){

	int N;
	cin >> N;
	vector<vector<pair<int, int> > > graph(N);
	vector<int> wealth(N);
	vector<int> parent(N);
	for(int i = 0; i < N; i++){
		cin >> wealth[i];
	}
	int boss;
	for(int i = 0; i < N; i++){
		cin >> parent[i];
		if(parent[i] == -1){
			boss = i;
		}
		else{
			parent[i] -= 1;
			graph[parent[i]].push_back(make_pair(i, wealth[i]));
		}
	}

	int maxValue = -1000000000;

	queue<pair<int, int> > q;

	q.push(make_pair(boss, wealth[boss]));

	while(!q.empty()){
		pair<int, int> temp = q.front();
		q.pop();
		for(vector<pair<int, int> >::iterator it = graph[temp.first].begin(); it != graph[temp.first].end(); it++){
			if(temp.second - it->second > maxValue){
				maxValue = temp.second - it->second;
			}
			q.push(make_pair(it->first, max(temp.second, it->second)));
		}
	}

	if(maxValue == -1000000000){
		maxValue = wealth[boss];
	}
	cout << maxValue;

	return 0;
}
