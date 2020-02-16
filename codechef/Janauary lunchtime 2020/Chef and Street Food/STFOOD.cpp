#include<iostream>
#include<vector>

using namespace std;
int main(){
	int T;
	cin >> T;

	for(int i = 0; i < T; i++){
		int N;
		cin >> N;
		int max = 0;
		for(int i = 0; i < N; i++){
			int S, P, V;
			cin >> S >> P >> V;
			S += 1;
			if((P/S) * V > max){
				max = (P/S) * V;
			}
		}
		cout << max << endl;
	}
}
