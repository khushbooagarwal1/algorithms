#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define test int t; cin >> t; for(; t> 0; t--)
#define INF -10000
	

int main() {
	//code
	test
	{
	    int n;
	    cin >> n;
	    vector< int > input(n);
	    int sum = 0, max_sum_so_far = INF;
	    for(int i = 0; i < n; i++){
	        cin >> input[i];
	        sum += input[i];
	        if(max_sum_so_far < sum){
	            max_sum_so_far = sum;
	        }
	        if(sum < 0){
	            sum = 0;
	        }
	    }
	    cout << max_sum_so_far << endl;
	}
	return 0;
}
