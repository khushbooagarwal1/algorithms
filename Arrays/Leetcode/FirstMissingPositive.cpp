/* https://leetcode.com/problems/first-missing-positive/ */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size() == 0){
            return 1;
        }
        int num = *min_element(nums.begin(), nums.end());
        if(num > 1){
            return 1;
        }
        else{
            num = 1;
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0 && nums[i] - num < nums.size() && nums[i] != nums[nums[i]-num]){
                int temp = nums[nums[i] - num];
                nums[nums[i] - num] = nums[i];
                nums[i] = temp;
                if(temp > 0 && temp - num < nums.size()){
                    i--;
                }
                
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]  != num+i){
                return num+i;
            }
        }
        return num+nums.size();
    }
};
