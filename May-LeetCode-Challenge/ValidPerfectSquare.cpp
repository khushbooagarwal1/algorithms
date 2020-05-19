/* https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3324/ */

class Solution {
public:
    bool isPerfectSquare(int num) {
        long sum = 0;
        for(int i = 1; sum < num; i+=2){
            sum += i;
            if(sum == num){
                return true;
            }
        }
        return false;
    }
};
