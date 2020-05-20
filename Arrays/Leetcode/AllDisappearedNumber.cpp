/* https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/ */

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if(i+1 != nums[i]){
                int temp = nums[nums[i]-1];
                if(nums[i] != temp){
                    nums[nums[i] - 1] = nums[i];
                    nums[i] = temp;
                    if(nums[i] != i+1){
                        i--;
                    }
                }
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i+1){
                res.push_back(i+1);
            }
        }
        return res;
    }
};
