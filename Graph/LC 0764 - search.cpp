/*
764. Largest Plus Sign
*/

// Solution 1: brute force O(n^3)

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<bool>>graph(n, vector<bool>(n, false));
        for(int i=0 ; i<mines.size() ; i++){
            graph[mines[i][0]][mines[i][1]] = true;
        }
        int ans = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                ans = max(ans, expand(graph, n, i, j));
            }
        }
        return ans;
    }
    
    int expand(vector<vector<bool>>& graph, int n, int x, int y){
        int k = 0;
        while(x + k < n && x - k >= 0 && y + k < n && y - k >= 0 
              && !graph[x+k][y] && !graph[x-k][y] && !graph[x][y+k] && !graph[x][y-k])
            k++;
        return k;
    }
};

// Solution 2: memorize 4 direction 1 O(n^2)

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>>graph(n, vector<int>(n, INT_MAX));
        for(int i=0 ; i<mines.size() ; i++){
            graph[mines[i][0]][mines[i][1]] = 0;
        }

        for(int i=0 ; i<n ; i++){
            int ctr = 1;
            for(int j=0 ; j<n ; j++, ctr++){
                if(graph[i][j] == 0)
                    ctr = 0;
                else
                    graph[i][j] = min(graph[i][j], ctr);
            }
            ctr = 1;
            for(int j=n-1 ; j>=0 ; j--, ctr++){
                if(graph[i][j] == 0)
                    ctr = 0;
                else
                    graph[i][j] = min(graph[i][j], ctr);
            }
        }
        
        for(int i=0 ; i<n ; i++){
            int ctr = 1;
            for(int j=0 ; j<n ; j++, ctr++){
                if(graph[j][i] == 0)
                    ctr = 0;
                else
                    graph[j][i] = min(graph[j][i], ctr);
            }
            ctr = 1;
            for(int j=n-1 ; j>=0 ; j--, ctr++){
                if(graph[j][i] == 0)
                    ctr = 0;
                else
                    graph[j][i] = min(graph[j][i], ctr);
            }
        }
        int ans = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(graph[i][j])
                    ans = ans > graph[i][j] ? ans : graph[i][j];
            }
        }        
        
        return ans;
    }

};


// Solution 3: more elegant of solution 2

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>>graph(n, vector<int>(n, INT_MAX));
        for(int i=0 ; i<mines.size() ; i++){
            graph[mines[i][0]][mines[i][1]] = 0;
        }

        for(int i=0 ; i<n ; i++){
            int north = 1, south = 1, west = 1, east = 1;
            for(int j=0 ; j<n ; j++, north ++, south ++, west ++, east ++){
                graph[i][j] = min(graph[i][j], west = (graph[i][j] == 0 ? 0 : west));
                graph[j][i] = min(graph[j][i], north = (graph[j][i] == 0 ? 0 : north));
                graph[i][n-j-1] = min(graph[i][n-j-1], east = (graph[i][n-j-1] == 0 ? 0 : east));
                graph[n-j-1][i] = min(graph[n-j-1][i], south = (graph[n-j-1][i] == 0 ? 0 : south));
            }
        }
        
        int ans = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(graph[i][j])
                    ans = ans > graph[i][j] ? ans : graph[i][j];
            }
        }        
        
        return ans;
    }

};