/* https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3328/ */


class Solution {
private:
    void getString(string num, int k, string& ans){
        if(num.size() <= k){
            return;
        }
        if(k == 0){
            ans += num;
            return;
        
        }
        int lowest = getLowest(num, k+1);
        if(ans.size() > 0 || num[lowest] != '0')
           ans += num[lowest];
        getString(num.substr(lowest + 1), k - lowest, ans);
        
    }
private:
    int getLowest(string num, int n){
        int small = 0;
        for(int i = 1; i < n; i++){
            if(num[small] > num[i]){
                small = i;
            }
        }
        return small;
    }
public:
    string removeKdigits(string num, int k) {
        if(num.size() <= k){
            return "0";
        }
        string ans = "";
        getString(num, k, ans);
        if(ans.size() == 0) return "0";
        return ans;
    }
};
