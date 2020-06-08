/* https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3351/ */


class Solution {
private:
    vector<int> sum;
public:
    Solution(vector<int>& a) {
        for(int i = 0; i < a.size(); i++){
               if(i == 0){ sum.push_back(a[0]);}
            else{
                sum.push_back(sum[i-1] + a[i]);
            }
        }
    }
    
    int pickIndex(){
        int num = int((float(rand())/RAND_MAX) * sum[sum.size() - 1]);
        return lower_bound(sum.begin(), sum.end(), num) - sum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
