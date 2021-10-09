/*
212. Word Search II
*/

class Solution {
public:
    
    vector<vector<int>> move = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n, m;
    
    struct TrimNode {
        vector<TrimNode*> vec;
        bool end;
        TrimNode(){
            vec.resize(26, nullptr);
            end = false;
        }
    };
    
    void appendWord(TrimNode *p, string & ss){
        for(auto &c: ss){
            if(!p->vec[c-'a']){
                TrimNode* newChar = new TrimNode;
                p->vec[c-'a'] = newChar;
            }
            p = p->vec[c-'a'];
        }
        p->end = true;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrimNode *root = new TrimNode;
        for(auto &i : words) appendWord(root, i);
        n = board.size();
        m = board[0].size();
        unordered_set<string> ans;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                char cur_c = board[i][j];
                if(root->vec[cur_c-'a']){
                    board[i][j] = '@';
                    dfs(board, root->vec[cur_c-'a'], {cur_c}, ans, i, j);
                    board[i][j] = cur_c;
                }
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
    
    void dfs(vector<vector<char>>& board, TrimNode* p, string ss, unordered_set<string>& ans, int x, int y){
        if(p->end) ans.insert(ss);
        for(int i=0 ; i<4 ; i++){
            int cur_x = x + move[i][0];
            int cur_y = y + move[i][1];
            if(cur_x >=0 && cur_x < n && cur_y >=0 && cur_y < m){
                char cur_c = board[cur_x][cur_y];
                if(cur_c != '@' && p->vec[cur_c-'a']){
                    board[cur_x][cur_y] = '@';
                    dfs(board, p->vec[cur_c-'a'], ss+cur_c, ans, cur_x, cur_y);
                    board[cur_x][cur_y] = cur_c;
                }
            }
        }
    }
};

// Solution 2: optimization of solution 1 using ctr

class Solution {
public:
    
    vector<vector<int>> move = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n, m;
    
    struct TrimNode {
        vector<TrimNode*> vec;
        int ctr;
        bool end;
        TrimNode(){
            vec.resize(26, nullptr);
            ctr = 0;
            end = false;
        }
    };
    
    void appendWord(TrimNode *p, string & ss){
        for(auto &c: ss){
            if(!p->vec[c-'a']){
                TrimNode* newChar = new TrimNode;
                p->vec[c-'a'] = newChar;
            }
            p->ctr ++;
            p = p->vec[c-'a'];
        }
        p->ctr++;
        p->end = true;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrimNode *root = new TrimNode;
        for(auto &i : words) appendWord(root, i);
        n = board.size();
        m = board[0].size();
        unordered_set<string> ans;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){               
                char cur_c = board[i][j];
                if(root->ctr && root->vec[cur_c-'a']){
                    board[i][j] = '@';
                    root->ctr -= dfs(board, root->vec[cur_c-'a'], {cur_c}, ans, i, j);
                    board[i][j] = cur_c;
                }
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
    
    int dfs(vector<vector<char>>& board, TrimNode* p, string ss, unordered_set<string>& ans, int x, int y){
        if(!p->ctr) return 0;
        int flag = 0;
        if(p->end) {
            ans.insert(ss);
            p->end = false;
            flag ++;
        }
        
        for(int i=0 ; i<4 ; i++){
            int cur_x = x + move[i][0];
            int cur_y = y + move[i][1];
            if(cur_x >=0 && cur_x < n && cur_y >=0 && cur_y < m){
                char cur_c = board[cur_x][cur_y];
                if(cur_c != '@' && p->vec[cur_c-'a']){
                    board[cur_x][cur_y] = '@';
                    flag += dfs(board, p->vec[cur_c-'a'], ss+cur_c, ans, cur_x, cur_y);
                    board[cur_x][cur_y] = cur_c;
                }
            }
        }
        p->ctr -= flag;
        return flag;
    }
};