#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define base 1000000
#define ulli unsigned long long int
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    vector< long int > t1;
    vector< long int > t2;
    t1.reserve(200);
    t2.reserve(200);
    
    int num1, num2, n;
    cin >> num1 >> num2 >> n;
    
    //insert number in the vector, each integer less than base value(5 digit)
    while(num1 > 0){
        t1.push_back(num1 % base);
        num1 /= base;
    }
    if(t1.size() == 0){
        t1.push_back(0);
    }
    while(num2 > 0){
        t2.push_back(num2 % base);
        num2 /= base;
    }
    if(t2.size() == 0){
        t2.push_back(0);
    }
    
    while(n >= 3){
        long int mul = 0;
        
        vector< long int > temp;    //for intermediate result
        temp.resize(t2.size()  + 1, 0);
        int len = temp.size();
        
        for(int i = 0; i < t2.size(); i++){
            for(int j = 0; j < t2.size(); j++){
                
                mul = (t2[i] * t2[j]);  //multiplication for square
                
                int k = i+j;        //each row will start with one gap
                int carry = 0;
                
                while(mul  > 0 || carry == 1){
                    if(k >= len){
                        temp.resize(k+1, 0);
                        len = k + 1;
                    }
                    //break product each into 5 digits and add with carry and previous row of mulitplication
                    long int sum = temp[k] + (mul % base) + carry;
                    temp[k] = (sum % base);
                    if(sum >= base){
                        carry = 1;
                    }
                    else{
                        carry = 0;
                    }
                    
                    mul /= base;
                    k++;
                }
            }
        }
        
        //increase temp size to avoid continuous reallocation
        if(t1.size() +1 > len){
            temp.resize(t1.size() + 1, 0);
            len = t1.size();
        }
        for(int i = 0; i < t1.size(); i++){
            long int sum = t1[i] + temp[i]; 
            temp[i] = (sum % base);
            int carry = 0, j  = i + 1;
            if(sum >= base){
                carry = 1;
            }
            
            while(carry == 1){
                sum = temp[j] + carry;
                temp[j] = sum % base;
                if(sum >= base){
                    carry = 1;
                }
                else{
                    carry = 0;
                }
                j++;
            }
        }
       t1 = t2;
       t2 = temp;
       n--;
    }
    int flag = 0;
    for(int i = t2.size()-1; i >= 0; i--){
        //if first , don't print preceding zero
        if(t2[i] != 0 && flag == 0){
            printf("%ld", t2[i]);
            flag = 1;
        }
        else if(flag == 1){
            printf("%06ld", t2[i]);
        }
    }
   return 0;
}
