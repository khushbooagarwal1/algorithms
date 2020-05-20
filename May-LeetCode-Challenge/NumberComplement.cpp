/* https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3319/ */

class Solution {
public:
    int findComplement(int num) {
        return num^int(pow(2, floor(log2(num)) + 1) - 1);
    }
};
