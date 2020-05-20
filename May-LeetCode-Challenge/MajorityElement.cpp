/* https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3321/ */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
            if(m[nums[i]] > nums.size() / 2){
                return nums[i];
            }
        }
        return -1;
    }
};
