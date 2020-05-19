/* https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3325/ */

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        map<int, int> trustedBy;
        vector<int> trusts(N+1, 0);
        
        for(int i = 0; i < trust.size(); i++){
            trustedBy[trust[i][1]]++;
            trusts[trust[i][0]]++;;
            
        }
        for(int i = 1; i <= N; i++ ){
            if(trusts[i] == 0 && trustedBy[i] == N-1){
                return i;
            }
        }
        return -1;
        
        
    }
};
