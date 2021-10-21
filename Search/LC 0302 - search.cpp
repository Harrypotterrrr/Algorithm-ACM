/*
302. Smallest Rectangle Enclosing Black Pixels
DFS, BFS, 
*/

// Solution 1: traverse all elements

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int n = image.size(), m = image[0].size();
        int min_x = INT_MAX, min_y = INT_MAX, max_x = INT_MIN, max_y = INT_MIN;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(image[i][j] == '1'){
                    min_x = min_x < i ? min_x : i;
                    min_y = min_y < j ? min_y : j;
                    max_x = max_x > i ? max_x : i;
                    max_y = max_y > j ? max_y : j;
                }
            }
        }
        return (max_x - min_x + 1) * (max_y - min_y + 1);
    }
};

// Solution 2: dfs

class Solution {
public:
    
    int n, m;
    int move[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int min_x = INT_MAX, min_y = INT_MAX, max_x = INT_MIN, max_y = INT_MIN;
    
    int minArea(vector<vector<char>>& image, int x, int y) {
        n = image.size();
        m = image[0].size();
        dfs(image, x, y);
        return (max_x - min_x + 1) * (max_y - min_y + 1);
    }
    
    void dfs(vector<vector<char>>& image, int x, int y) {
        min_x = min_x < x ? min_x : x;
        min_y = min_y < y ? min_y : y;
        max_x = max_x > x ? max_x : x;
        max_y = max_y > y ? max_y : y;
        image[x][y] = '2';

        for(int i=0 ; i<4 ; i++){
            int cur_x = x + move[i][0];
            int cur_y = y + move[i][1];
            if(cur_x >= 0 && cur_y >= 0 && cur_x < n && cur_y < m && image[cur_x][cur_y] == '1'){
                dfs(image, cur_x, cur_y);
            }
        }
    }
    
};


// Solution 3: bfs

class Solution {
public:
    
    int minArea(vector<vector<char>>& image, int x, int y) {
        
        int n = image.size(), m = image[0].size();
        int move[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int min_x = INT_MAX, min_y = INT_MAX, max_x = INT_MIN, max_y = INT_MIN;
        queue<pair<int,int>> Q({{x, y}});
        image[x][y] = '2';
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            // cout<<cur.first<<" "<<cur.second<<endl;
            min_x = min_x < cur.first ? min_x : cur.first;
            min_y = min_y < cur.second ? min_y : cur.second;
            max_x = max_x > cur.first ? max_x : cur.first;
            max_y = max_y > cur.second ? max_y : cur.second;

            for(int i=0 ; i<4 ; i++){
                int cur_x = cur.first + move[i][0];
                int cur_y = cur.second + move[i][1];
                if(cur_x >= 0 && cur_y >= 0 && cur_x < n && cur_y < m && image[cur_x][cur_y] == '1'){
                    image[cur_x][cur_y] = '2';
                    Q.push({cur_x, cur_y});
                }
            }
        }
        return (max_x - min_x + 1) * (max_y - min_y + 1);
        
    }
};

