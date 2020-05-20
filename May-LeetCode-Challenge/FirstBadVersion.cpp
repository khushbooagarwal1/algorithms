/* https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3316/ */


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
private:
    int find(int low, int high){
        int ans = 0;
        if(low > high){
            return 0;
        }
        if(low == high){
            if(isBadVersion(low)){
                return low;
            }
            return 0;
        }
        if(isBadVersion(int((long(low)+long(high)) / 2))){
            ans = find(low, int((long(low)+long(high))/ 2) - 1);
            if(ans != 0){
                return ans;
            }
            else{
                return int((long(low)+long(high)) / 2);
            }
        }
        return find(int((long(low)+long(high)) / 2) + 1, high);

    }

public:
    int firstBadVersion(int n) {
        return find(1, n);
    }
};
