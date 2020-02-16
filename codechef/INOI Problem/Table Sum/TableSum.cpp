#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> input(N);
	int maxRes = 0, pos = -1;
	for(int i = 0; i < N; i++){
		cin >> input[i];
		input[i] += (i+1);
		if(input[i] > maxRes){
			maxRes = input[i];
			pos = i;
		}
	}

	cout << maxRes;
	int last = 0;

	for(int j = 1; j < N; j++){
		int it = N-j;
		if(pos != it){
			maxRes += 1;
		}
		else{
			maxRes = 0;
			for (int i = 0; i < N; ++i)
			{
				int temp;
				if(i >= it) {
					temp = input[i] - N + j;
				}
				else{
					temp = input[i] + j;
				}
				if(temp > maxRes){
					maxRes = input[i];
					pos = i;
				}
			}
			last = j;
		}
		cout << " " << maxRes;
	}



	return 0;
}
