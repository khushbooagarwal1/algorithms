/* https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3336/ */


class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        for(int i = 0; i< matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(i >= 1 && j >= 1 && matrix[i-1][j] > 0 && matrix[i][j-1] > 0 && matrix[i-1][j-1] > 0 && matrix[i][j] > 0){
                    matrix[i][j] = min(min(matrix[i][j-1], matrix[i-1][j]), matrix[i-1][j-1]) + 1;
                }
                ans += matrix[i][j];
            }
        }
        return ans;
    }
};
