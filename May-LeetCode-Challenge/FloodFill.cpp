/* https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3326/ */

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int x[] = { 1, 0, -1, 0 };
        int y[] = { 0, 1, 0, -1 };
        queue<pair<int, int>> q;
        q.push(make_pair(sr, sc));
        int color = image[sr][sc];
        vector<vector<int>> visited(image.size(), vector<int>(image[0].size(), 0));
        image[sr][sc] = newColor;
        visited[sr][sc] = 1;
        while(!q.empty()){
            pair<int, int> p = q.front();
            for(int i = 0; i < 4; i++){
                int newX = p.first + x[i];
                int newY = p.second + y[i];
                if(newX >= 0 && newX < image.size() && newY >= 0 && newY < image[0].size() && image[newX][newY] == color && visited[newX][newY] != 1){
                    image[newX][newY] = newColor;
                    q.push(make_pair(newX, newY));
                    visited[newX][newY] = 1;
                }
            }
            q.pop();
        }
        return image;
        
    }
};
