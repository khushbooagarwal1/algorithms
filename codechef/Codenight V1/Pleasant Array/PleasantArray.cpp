#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{	
	int N;
	cin >> N;
	vector<long> array(N);
	for(int i = 0; i < N; i++){
		cin >> array[i];
	}
	sort(array.begin(), array.end());
	for(int i = 1; i < N; i++){
		if(abs(array[i] - array[i-1]) != 1){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	/* code */
	return 0;
}
