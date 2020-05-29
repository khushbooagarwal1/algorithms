/* https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3343/ */

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1, 0);
        if(num >= 1){
            ans[1] = 1;
        }
        int counter = 0;
        for(int i = 2; i <= num; i++){
            if(pow(2, int(log2(i))) == i){
                counter = 0;
            }
            ans[i] = ans[counter] + 1;
            counter++;
        }
        return ans;
    }
};
