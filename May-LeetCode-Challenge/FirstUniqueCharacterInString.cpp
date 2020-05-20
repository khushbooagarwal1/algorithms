/* https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3320/ */

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count(26, 0);
        vector<int> index(26, -1);
        for(int i = 0; i < s.size(); i++){
            count[s[i] - 'a']++;
            index[s[i] - 'a'] = i;
        }
        int ans = s.size();
        for(int it = 0; it < count.size(); it++){
            if(count[it] == 1 && index[it] < ans){
                ans = index[it];
            }
        }
        return ans == s.size() ? -1 : ans;
    }
};
