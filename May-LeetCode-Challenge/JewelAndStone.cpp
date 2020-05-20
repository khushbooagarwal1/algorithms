/* https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3317/ */

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char, int> jewelMap;
        for(int i =0; i< J.size(); i++){
            jewelMap[J[i]]++;
        }
        int count = 0;
        for(int i = 0; i < S.size(); i++){
            if(jewelMap[S[i]] == 1){
                count++;
            }
        }
        return count;
        
    }
};
