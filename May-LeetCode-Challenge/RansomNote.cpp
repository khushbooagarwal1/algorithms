/* https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3318/ */

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> magazineMap;
        for(int i = 0; i < magazine.size(); i++){
            magazineMap[magazine[i]]++;
        }
        for(int i = 0; i < ransomNote.size(); i++){
            if(magazineMap[ransomNote[i]] == 0){
                return false;
            }
            magazineMap[ransomNote[i]]--;
        }
        return true;
    }
};
