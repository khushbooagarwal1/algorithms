/* https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3349/ */

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [ ]( const vector<int>& lhs, const vector<int>& rhs ){
            return abs(lhs[0]-lhs[1]) > abs(rhs[0] - rhs[1]);
        });      
        int a = 0; int b = 0;
        int ans = 0;
        for(int i = 0; i < costs.size(); i++){
            if((costs[i][0] < costs[i][1] && a < costs.size()/2) || b >= costs.size()/2){
                ans += costs[i][0];
                a++;
            }
            else if(b < costs.size()/2){
                ans += costs[i][1];
                b++;
            }
        }
        return ans;
    }
};
