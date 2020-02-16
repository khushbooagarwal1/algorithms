v#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(std::vector<long> v1, std::vector<long> v2){
	return v1[0] + v1[1] + v1[2] == v2[0] + v2[1] + v2[2] ? v1[0] < v2[0] :v1[0] + v1[1] + v1[2] > v2[0] + v2[1] + v2[2];
}

int main() {

	int N;
	cin >> N;
	vector< vector<long> > time(N);

	for(int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		time[i].push_back(a);
		time[i].push_back(b);
		time[i].push_back(c);
	}

	sort(time.begin(), time.end(), compare);

	long maxTime = -1;
	for(int i = 0; i < N; i++){
		long temp = time[i][0] + time[i][1] + time[i][2];
		if(temp > maxTime){
			maxTime = temp;
		}
		if(i < N-1){
			time[i+1][0] += time[i][0];
		}
	}
	cout << maxTime;

	return 0;
}
