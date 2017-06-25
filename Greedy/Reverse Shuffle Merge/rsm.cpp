#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int smallest(vector< int >& req){
    int len = req.size();
    for(int i = 0; i< len; i++){
        if(req[i] != 0 ){
            return i;
        }
    }
    return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string  s;
    cin >> s;
    int len = s.size();
    string a ="";
    a.resize(len);
    vector< int >freq(26, 0);
    vector< int >req_a(26, 0);
    //count of each character
    for(int i = 0; i < len; i++){
        freq[s[i]-'a']++;
    }
    //count of each character required at an instance for A
    for(int i = 0; i < len; i++){
        req_a[s[i]-'a'] = freq[s[i]-'a'] / 2;
    }
    //checkpoint = last character which was inserted correctly
    //j = last character which was inserted
    int j = -1, checkpoint = -1;
    
    for(int i = len- 1; i >= 0 && checkpoint < len/ 2; i--){
        //if the character can't be skipped as all remaining are needed
        //if character is lowest character possible in the remaining one
        if((req_a[s[i] - 'a'] == freq[s[i] - 'a']) || (req_a[s[i] - 'a'] > 0 && (s[i] - 'a') == smallest(req_a))){
            int k;
            //discard any character inserted after last checkpoint which is bigger than current one
            for(k = j; k > checkpoint; k--){
                if(a[k] < s[i]){
                    break;
                }
            }
            //fix rest and decrease requirement for them
            int temp = checkpoint + 1;
            for(; temp <= k; temp++){
               // cout << s[temp] << endl;;
                req_a[a[temp] - 'a']--;
            }
            //insert current character
            a[k+1] = s[i];
            j = k + 1;
            //update checkpoint
            checkpoint = j;
            req_a[s[i] - 'a']--;
        }
        else if(req_a[s[i] - 'a'] > 0){
            //if the charecter has requirement
            //remove those character which are bigger than the current character
            while(j > checkpoint && s[i] < a[j]){
                j--;
            }
            j++;
            a[j] = s[i];
            
         }
         //for each visited character, decrease the frequency
        freq[s[i] - 'a']--;
    }
    a[checkpoint+1] = 0;
    a.resize(len/ 2);
    cout << a;
    return 0;
}
