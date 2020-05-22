/* https://leetcode.com/explore/featured/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3337/ */

class Solution {

public:
    string frequencySort(string s) {
        
        map<char, int> countMap;
        for(int i = 0; i < s.size(); i++){
            countMap[s[i]]++;
        }
        vector<pair<int, char>> countVector;
        for(int i = 0; i < s.size(); i++){
            countVector.push_back(make_pair(countMap[s[i]], s[i]));
        }
        sort(countVector.rbegin(), countVector.rend());
        string ans = "";
        for(auto it = countVector.begin(); it != countVector.end(); it++){
            ans += it->second;
        }
        return ans;
    }
};
