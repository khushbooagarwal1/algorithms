#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include<utility>
#include<map>
using namespace std;
int main(){
	int T;
	cin >> T;

	for(int i = 0; i < T; i++){
		int N, M, W, H;
		cin >> N >> M >>W >> H;
		
		string s;
		cin >> s;
		map<char, bool> m;
		m['L'] = s.find('L') != -1;
		m['R'] = s.find('R') != -1;
		m['U'] = s.find('U') != -1;
		m['D'] = s.find('D') != -1;
		vector<pair<int, int> > point;
		double dist = 100000000000;
		for(int j = 0; j < M; j++){
			double x, y;
			cin >> x >> y;
			point.push_back(make_pair(x, y));
			if(m['L'] == true && x <= W/2){
				dist = min(dist, 2*x);
			}

			if(m['R'] == true && x >= W/2){
				dist = min(dist, 2*(W-x));
			}

			if(m['U'] == true && y <= H/2){
				dist = min(dist, 2*y);
			}

			if(m['D'] == true && y >= H/2){
				dist = min(dist, 2*(H-y));
			}
			for(int k = j-1; k >= 0; k--) {
				dist = min(dist, sqrt(((point[k].first - x) * (point[k].first - x)) + ((point[k].second - y) * (point[k].second - y))));
			}
		}
		cout << dist << endl;
	}
	return 0;
}
