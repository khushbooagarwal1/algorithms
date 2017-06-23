#include <cmath>
#include <cstdio>
#include <iostream> 
#include <set>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, k; #number of flower, group of friends
    cin >> n >> k;
    set < int > flower;
    for(int i = 0; i <n; i++){
        int price;
        cin >> price;
        flower.insert(price);
    }
    int price = 0;
    int count = 0;
    //get maximum element always
    set< int >::reverse_iterator it = flower.rbegin();
    while(it != flower.rend()){
        //(count / k) increases after ever k step. So after k purchase, price would increase
        price += (((count / k) + 1) * *it);
        it++;
        count++;
    }
    cout << price << endl;
    return 0;
}
