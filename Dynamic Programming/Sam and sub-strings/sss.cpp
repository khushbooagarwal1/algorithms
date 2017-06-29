#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#define MOD 1000000007
#define sz(x) x.size()
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    string s;
    cin >> s;
    int l = sz(s);
    long long int res = 0;
    long long int f = 1;
    //unit digit(u) can occur at only on unit position in substrings, so u*1, that too num_digit times
    //ones(o) digir can occur at unit and tens position,so (o*11), that too num_digit - 1 times
    for(int i = l-1; i >= 0; i--) {
        //(i+1) denotes frequency at each position
        res = (res + (s[i]-'0')*f*(i+1)) % MOD;
        f = (f*10+1) % MOD;         //1,11,111,....
    }
    cout << res << endl;
    return 0;
}
