/* https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3340/ */

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1, 0));
        int tot_max = 0;
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < B.size(); j++){
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                if(A[i] == B[j]){
                    dp[i+1][j+1] = max(dp[i][j] + 1, dp[i+1][j+1]);
                }
                if(dp[i+1][j+1] > tot_max){
                        tot_max = dp[i+1][j+1];
                    }
            }
        }
        return tot_max;
    }
};
