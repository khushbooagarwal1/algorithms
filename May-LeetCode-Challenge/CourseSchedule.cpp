/* https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/3344/ */

class Solution {
    
private:
    bool checkCyclic(map<int, vector<int>>adj, vector<bool>& visited, vector<bool>& recStack, int sub1)     {
        if(!visited[sub1]) {
            visited[sub1] = true;
            recStack[sub1] = true;
            for(auto sub2 = adj[sub1].begin(); sub2 != adj[sub1].end(); sub2++){
                if ( !visited[*sub2] && checkCyclic(adj, visited, recStack, *sub2)){ 
                    return true; 
                }
                else if (recStack[*sub2]){
                    return true;     
                }
            }
        }
        recStack[sub1] = false;
        return false; 
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>>adj;
        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> recursionStack(numCourses, false);
        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                if(checkCyclic(adj, visited, recursionStack, i) == true){
                    return false;
                }
            }
        }
        return true;
    }
};
