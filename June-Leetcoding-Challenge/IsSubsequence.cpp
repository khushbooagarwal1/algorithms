/* https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3355/ */


class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<bool>>dp(s.size()+1, vector<bool>(t.size() + 1, false));
        for(int i = 0; i <= t.size(); i++){
            dp[0][i] = true;
        }
        for(int i = 1; i <= s.size(); i++){
            for(int j = 1; j <= t.size(); j++){
                dp[i][j] = (s[i-1] == t[j-1] && dp[i-1][j-1]) || dp[i][j-1];
            }
        }
        return dp[s.size()][t.size()];
    }
};
