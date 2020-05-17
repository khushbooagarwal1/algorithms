/* https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3327/ */

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i += 2){
            if(i+1 == nums.size() || nums[i] != nums[i+1]){
                return nums[i];
            }
        }
        return 0;
        
    }
};
