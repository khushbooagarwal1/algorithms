/* https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/3345/ */

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue <pair<long, int>, vector<pair<long,int>>, greater<pair<long, int>>> p;
        for(int i = 0; i <points.size(); i++){
            p.push(make_pair(points[i][0] * points[i][0] + points[i][1] * points[i][1], i));
        }
        vector<vector<int>> ans;
        while(!p.empty() && K > 0){
            ans.push_back(points[p.top().second]);
            p.pop();
            K--;
        }
        return ans;
        
    }
};
