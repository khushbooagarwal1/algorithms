/* https://leetcode.com/explore/featured/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3332/ */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        map<char, int> pMap;
        map<char, int> sMap;
        for(int i = 0; i < p.size(); i++){
            pMap[p[i]]++;
        }
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if(count > 0 && pMap[s[i]] > 0 && pMap[s[i]] <= sMap[s[i]]){
                int j = i-count;
                for(; j < i; j++){
                    sMap[s[j]]--;
                    if(s[j] == s[i]){
                        break;
                    }
                }
                count = i - j - 1;
            }
            if(pMap[s[i]] > sMap[s[i]]){
                count++;
                sMap[s[i]]++;
            }
            else{
                count = 0;
                for(int i = 0; i < p.size(); i++){
                    sMap[p[i]] = 0;
                }
            }
            if(count == p.size()){
                result.push_back(i + 1 - p.size());
                sMap[s[i + 1 - p.size()]]--;
                count--;
            }
        }
        return result;
    }
};
