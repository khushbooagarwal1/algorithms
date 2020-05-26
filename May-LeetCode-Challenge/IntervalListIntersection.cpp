/* https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3338/ */

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>>output;
        int low, high, flag;
        int i = 0; 
        int j = 0;
        while(i < A.size() && j < B.size()){
            flag = 0;
            if(A[i][0] <= B[j][0] && A[i][1] >= B[j][0]){
                low = B[j][0];
                flag = 1;
            }
            else if(B[j][0] <= A[i][0] && B[j][1] >= A[i][0]){
                low = A[i][0];
                flag = 1;
            }
            
            if(flag == 1){
                if(B[j][1] <= A[i][1]){
                    high = B[j][1];
                    j++;
                }
                else{
                    high = A[i][1];
                    i++;
                }
                vector<int>out{low, high};
                output.push_back(out);
            }
            else if(B[j][1] < A[i][0]){
                j++;
            }
            else{
                i++;
            }
        }
        return output;
    }
};
