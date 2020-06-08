/* https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3353/ */

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size() + 1, vector<int>(amount+1, 0));
        for(int i = 0; i <= coins.size(); i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i <= coins.size(); i++){
            for(int j = 1; j <= amount; j++){
                dp[i][j] = dp[i-1][j];
                if(coins[i-1] <= j){
                    dp[i][j] += dp[i][j-coins[i-1]];
                }
            }
        }
    return dp[coins.size()][amount];
        
    }
};
