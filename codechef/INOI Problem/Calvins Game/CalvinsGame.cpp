#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, k;
	cin >> N >> k;
	vector< int> square(N);
	for(int i = 0; i < N; i++) {
		cin >> square[i];
	}
	k -= 1;
	std::vector<int> sum(N);
	sum[k] = 0;
	for (int i = k+1; i < N; ++i)
	{
		if(i == k+1){
			sum[i] = sum[i-1];
		}
		sum[i] = max(sum[i-1] + square[i], sum[i-2] + square[i]);

	}

	std::vector<int> finalSum(N);
	for (int i = N-1; i >= 0; --i)
	{
		if(i == N - 1){
			finalSum[i] = sum[i];
		}
		else if(i == N -2){
			finalSum[i] = finalSum[i+1] + square[i];
		}
		else{
			finalSum[i] = max(finalSum[i+1] + square[i], finalSum[i+2] + square[i]);
		}
		if(i >= k){
			finalSum[i] = max(finalSum[i], sum[i]);
		} 
	}
	
	cout << finalSum[0];
}
