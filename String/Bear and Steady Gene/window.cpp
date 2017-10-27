#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    string str;
    cin >> str;
    int g = 0, t = 0, a = 0 , c = 0;
    
    //extra character will be removed
    map< char, int > extra;
    extra['G'] = -n/4;
    extra['T'] = -n/4;
    extra['C'] = -n/4;
    extra['A'] = -n/4;
    
    map< char, int > found;
    
    int s = 0;    //how many characters are extra in total
    for(int i = 0; i < n; i++){
        extra[str[i]]++;
        
        //positive extras has to be removed
        if(extra[str[i]] > 0){
            s++;
        }
    }
    int begin = 0, end = 0, count = 0, ans = 5000001;
    while(end < n){
        
        //when you found all the characters you want
        if(found[str[end]] < extra[str[end]]){
            count++;
        }
        
        found[str[end]]++;
        end++;
        
        //when you have a window containing all extra characters
        if(count == s){
            //if the character in window was not extra at all, remove it
            //as you are doing noting but replacing that character by itself only.. better remove it.
            while(found[str[begin]] > extra[str[begin]]){
                found[str[begin]]--;
                begin++;
            }
            
            if(ans > (end-begin)){
                ans = end-begin;
            }
        }
    }
    cout << ans;
    return 0;
}
