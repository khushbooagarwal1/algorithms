/* https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3323/ */

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        float m;
        int flag = 0;
        if(coordinates[0][0] - coordinates[1][0] == 0){
            m = 0;
            flag = 1;
        }
        else{
            m = float(coordinates[0][1] - coordinates[1][1]) / float(coordinates[0][0] - coordinates[1][0]);
        }
            
        for(int i = 1; i < coordinates.size() - 1; i++){
            float newM;
            if(coordinates[i+1][0] - coordinates[i][0] == 0){
                newM = 0;
                if(flag == 0){
                    return false;
                }
            }
            else{
                newM = float(coordinates[i+1][1] - coordinates[i][1]) / float(coordinates[i+1][0] - coordinates[i][0]);
                if(flag == 1){
                    return false;
                }
            }
            if(newM != m){
                return false;
            }
        }
        return true;
        
    }
};
