/* https://www.codechef.com/JUNE20A/problems/EOEO */

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
	    long ts;
	    cin >> ts;
	    while(ts % 2 == 0){
	        ts/=2;
	    }
	    cout << (ts-1) / 2 << endl;
	}
	return 0;
}
