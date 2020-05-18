/* https://leetcode.com/explore/featured/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3333/ */

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> count1;
        map<char, int> count2;
        for(int i = 0; i < s1.size(); i++){
            count1[s1[i]]++;
        }
        int matchedLen = 0;
        for(int i = 0; i < s2.size(); i++){
            if(count1[s2[i]] > 0 && count1[s2[i]] == count2[s2[i]]){
                for(int j = i - matchedLen; j < i; j++){
                    count2[s2[j]]--;
                    matchedLen--;
                    if(s2[j] == s2[i]){
                        break;
                    }
                }
                
            }
            if(count1[s2[i]] > count2[s2[i]]){
                matchedLen++;
                count2[s2[i]]++;
            }
            else if(matchedLen > 0){
                for(int j = i-matchedLen; j < i; j++){
                    count2[s2[j]] = 0;
                }
                matchedLen = 0;
            }
            if(matchedLen == s1.size()){
                break;
            }
        }
        return matchedLen == s1.size();
    }
};
