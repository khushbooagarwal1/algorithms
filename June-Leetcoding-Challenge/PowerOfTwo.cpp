/* https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3354/ */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && int(log2(n)) == ceil(log2(n));
    }
};
