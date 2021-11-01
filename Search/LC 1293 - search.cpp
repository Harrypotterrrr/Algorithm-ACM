/************************************************
Problem: 		1293. Shortest Path in a Grid with Obstacles Elimination
Algorithm: 		Search, BFS, STL
Difficulty: 	***
Importance:		*****
Remark:			
*************************************************/

// Solution 1: bfs + lambda hashing unordered_set to int

class Solution {
public:
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int move[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int n = grid.size(), m = grid[0].size();
        queue<pair<pair<int, int>, int> >Q({{{0, 0}, k}});
        auto hash = [](const pair<pair<int, int>, int>& p){ 
            return p.second * 1600 + p.first.second * 40 + p.first.second;
        };
        unordered_set<pair<pair<int, int>, int>, decltype(hash) > uS(1600*1600+1, hash);
        uS.insert({{0, 0}, k});
        int ans = 0;
        while(!Q.empty()){
            for(int j=Q.size()-1 ; j>=0 ; j--){
                auto cur = Q.front(); Q.pop();
                if(cur.first.first == n-1 && cur.first.second == m-1) return ans;
                for(int i=0 ; i<4 ; i++){
                    int x = cur.first.first + move[i][0];
                    int y = cur.first.second + move[i][1];
                    int cur_k = cur.second;
                    if(x >= 0 && x < n && y >= 0 && y < m){
                        if(grid[x][y] == 1 && cur_k > 0 && uS.find({{x, y}, cur_k-1}) == uS.end()){
                            uS.insert({{x, y}, cur_k-1});
                            Q.push({{x, y}, cur_k-1});
                        }
                        else if(grid[x][y] == 0 && uS.find({{x, y}, cur_k}) == uS.end()){
                            uS.insert({{x, y}, cur_k});
                            Q.push({{x, y}, cur_k});
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};

// Solution 2: bfs + unordered_set with string

class Solution {
public:
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int move[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int n = grid.size(), m = grid[0].size();
        queue<pair<pair<int, int>, int> >Q({{{0, 0}, k}});
        unordered_set<string> uS;
        uS.insert(to_string(0) + "," + to_string(0) + "," + to_string(k));
        int ans = 0;
        while(!Q.empty()){
            for(int j=Q.size()-1 ; j>=0 ; j--){
                auto cur = Q.front(); Q.pop();
                if(cur.first.first == n-1 && cur.first.second == m-1) return ans;
                for(int i=0 ; i<4 ; i++){
                    int x = cur.first.first + move[i][0];
                    int y = cur.first.second + move[i][1];
                    int cur_k = cur.second;
                    if(x >= 0 && x < n && y >= 0 && y < m){
                        if(grid[x][y] == 1 && cur_k > 0){
                            string tmp = to_string(x) + "," + to_string(y) + "," + to_string(cur_k-1);
                            if(uS.find(tmp) == uS.end()){
                                uS.insert(tmp);
                                Q.push({{x, y}, cur_k-1});
                            }
                        }
                        else if(grid[x][y] == 0){
                            string tmp = to_string(x) + "," + to_string(y) + "," + to_string(cur_k);
                            if(uS.find(tmp) == uS.end()){
                                uS.insert(tmp);
                                Q.push({{x, y}, cur_k});
                            }
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};

// Solution 3: TODO bfs + using defined datatype + hashing unordered set to string + std::hash mapping string to size_t

class Solution {
public:
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int move[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int n = grid.size(), m = grid[0].size();
        using triad = pair<pair<int, int>, int>;
        queue<triad >Q({{{0, 0}, k}});
        auto hashing = [](const triad & p)-> size_t {
            return hash<string>()(to_string(p.first.first) + "-" + to_string(p.first.second) + "-" + to_string(p.second));
        };
        unordered_set<triad, decltype(hashing)> uS(1600*1600+1, hashing);
        uS.insert({{0, 0}, k});
        int ans = 0;
        while(!Q.empty()){
            for(int j=Q.size()-1 ; j>=0 ; j--){
                auto cur = Q.front(); Q.pop();
                if(cur.first.first == n-1 && cur.first.second == m-1) return ans;
                for(int i=0 ; i<4 ; i++){
                    int x = cur.first.first + move[i][0];
                    int y = cur.first.second + move[i][1];
                    int cur_k = cur.second;
                    if(x >= 0 && x < n && y >= 0 && y < m){
                        if(grid[x][y] == 1 && cur_k > 0 && uS.find({{x, y}, cur_k-1}) == uS.end()){
                            uS.insert({{x, y}, cur_k-1});
                            Q.push({{x, y}, cur_k-1});
                        }
                        else if(grid[x][y] == 0 && uS.find({{x, y}, cur_k}) == uS.end()){
                            uS.insert({{x, y}, cur_k});
                            Q.push({{x, y}, cur_k});
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};

// Solution 4: use visited 2-dimensional array to optimize the unordered_set

class Solution {
public:
    
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int move[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int n = grid.size(), m = grid[0].size();
        using triad = pair<pair<int, int>, int>;
        queue<triad >Q({{{0, 0}, k}});
        vector<vector<int>> visited(n, vector<int>(m, -1));
        visited[0][0] = k;
        int ans = 0;
        while(!Q.empty()){
            for(int j=Q.size()-1 ; j>=0 ; j--){
                auto cur = Q.front(); Q.pop();
                if(cur.first.first == n-1 && cur.first.second == m-1) return ans;
                for(int i=0 ; i<4 ; i++){
                    int x = cur.first.first + move[i][0];
                    int y = cur.first.second + move[i][1];
                    int cur_k = cur.second;
                    if(x >= 0 && x < n && y >= 0 && y < m){
                        if(grid[x][y] == 1 && cur_k > 0 && visited[x][y] < cur_k - 1){
                            visited[x][y] = cur_k - 1;
                            Q.push({{x, y}, cur_k-1});
                        }
                        else if(grid[x][y] == 0 && visited[x][y] < cur_k){
                            visited[x][y] = cur_k;
                            Q.push({{x, y}, cur_k});
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};

// Solution 5: A star TODO