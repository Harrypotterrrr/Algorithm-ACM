/*
733. Flood Fill
*/

// Solution 1: dfs

class Solution {
public:
    int move[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int n, m;

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size(); m = image[0].size();
        if(newColor != image[sr][sc])
            dfs(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
    
    void dfs(vector<vector<int>>&image, int x, int y, int newColor, int oldColor){
        image[x][y] = newColor;
        
        for(int i=0 ; i<4 ; i++){
            int cur_x = x + move[i][0];
            int cur_y = y + move[i][1];
            if(cur_x < n && cur_x >= 0 && cur_y >= 0 && cur_y < m && image[cur_x][cur_y] == oldColor){
                dfs(image, cur_x, cur_y, newColor, oldColor);
            }
        }
        return;
    }
};

// Solution 2: bfs

class Solution {
public:

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int move[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int n, m;
        n = image.size(); m = image[0].size();
        
        queue<pair<int,int>>Q;
        int oldColor = image[sr][sc];
        if(newColor == oldColor) return image;
        image[sr][sc] = newColor;
        Q.push({sr, sc});
        while(!Q.empty()){
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            for(int i=0 ; i<4 ; i++){
                int cur_x = x + move[i][0];
                int cur_y = y + move[i][1];
                if(cur_x < n && cur_x >= 0 && cur_y >= 0 && cur_y < m && image[cur_x][cur_y] == oldColor){
                    image[cur_x][cur_y] = newColor;
                    Q.push({cur_x, cur_y});
                }
            }
        }
        return image;
    }

};
