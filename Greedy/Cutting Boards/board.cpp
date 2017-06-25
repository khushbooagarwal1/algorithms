#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define modulo 1000000007
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    cin >> t;
    for(; t > 0; t--){
        int n, m;
        cin >> n >> m;
        //to store height and width cost
        vector< long int > y(n-1);
        vector< long int > x(m-1);
        for(int i = 0; i < n-1; i++){
            cin >> y[i];
        }
        for(int i = 0; i < m-1; i++){
            cin >> x[i];
        }
        //sort in descending order to choose maximum cost 
        sort(x.rbegin(), x.rend());
        sort(y.rbegin(), y.rend());
        int j = 0, k = 0;
        long cost = 0;
        //xcount = number of horizontal segement created
        //ycount = number if vertical segement
        int xcount = 1, ycount = 1;
        while(j < m-1 && k < n-1){
            //always cut in the direction with maximum cost, as cost increases linearly with number of segements present
            if(x[j] >= y[k]){
                //cut horizontally for each vertical segement
                cost = (cost + ((ycount * x[j])% modulo)) % modulo;
                xcount++;   //horizonatal segement
                j++;
            }
            else{
                //cut vertically for each horizontal segement
                cost = (cost + ((xcount * y[k])% modulo)) % modulo;
                ycount++;   //vertical segement
                k++;
            }
        }
        //iterate for if breaking in one direction is left
        if(j < m-1){
            for(;j < m-1; j++){
               cost = (cost + ((ycount * x[j])% modulo)) % modulo;
            }
        }
        if(k < n-1){
            for(;k < n-1; k++){
               cost = (cost + ((xcount * y[k])% modulo)) % modulo;
            }
        }
        cout << cost << endl;
    }
    
    return 0;
}
