/* https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3342/ */

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        map<int, vector<int>> adj;
        vector<int> group(N+1, 0);
        for(int i = 0; i < dislikes.size(); i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        queue<int> nodes;
        for(int i = 1; i < N; i++){
            if(group[i] == 0) {
                nodes.push(i);
                group[i] = 1;
                while(!nodes.empty()){
                    int source = nodes.front();
                    nodes.pop();
                    for(auto dest = adj[source].begin(); dest != adj[source].end(); dest++){
                        if(group[*dest] == 0){
                            group[*dest] = group[source] == 1 ? 2 : 1;
                            nodes.push(*dest);
                        }
                        else if(group[*dest] == group[source]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
