#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	for(; t > 0; t--){
        int n;
        cin >> n;
        if(n > 0){
        vector< int > input(n);
        vector< int > result(n, 1);

        for(int i = 0; i < n; i++){
            cin >> input[i];
            if(i > 0){
                int cur_max = 1;
                for(int j = i - 1; j >= 0; j--){
                    if(input[i] > input[j] && cur_max < result[j] + 1){
                        cur_max = result[j] + 1;
                    }
                    if(cur_max >= j + 2){
                        break;
                    }
                }
                result[i] = cur_max;
            }
        }
        cout << *max_element(result.begin(), result.end()) << endl;
        }
        else{
            cout << 0 << endl;
        }
	}
	return 0;
}
