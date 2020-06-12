/* https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3357/ */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int first = 0, last = nums.size() - 1;
        for(int i = 0; i <= last; i++){
            if(nums[i] == 0){
                if(i != first) {
                    int temp = nums[first];
                    nums[first] = nums[i];
                    nums[i] = temp;
                    i--;
                }
                first++;
            }
            else if(nums[i] == 2){
                if(i != last) {
                    int temp = nums[last];
                    nums[last] = nums[i];
                    nums[i] = temp;
                    i--;
                }
                last--;
            }
        }
        
    }
};
