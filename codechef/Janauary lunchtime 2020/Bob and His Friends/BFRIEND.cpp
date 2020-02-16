#include<iostream>
#include<algorithm>

using namespace std;
int main(){
	int T;
	cin >> T;

	for(int i = 0; i < T; i++){
		int N, A, B, C;
		cin >> N >> A >> B >> C;
		long time = 4000000000;
		for(int i = 0; i < N; i++){
			int F;
			cin >> F;
			time = min(long(max(B, F) - min(B, F)) + long(max(A, F) - min(A, F)) + C, time);
		}
		cout << time << endl;
	}
}
