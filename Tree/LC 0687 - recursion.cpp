/*
687. Longest Univalue Path
*/

// Solution 1: recursion

class Solution {
public:
    int ans = 0;
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int maxn = 0;
        solve(root, -1001, maxn);
        return ans-1;
    }
    
    void solve(TreeNode* node, int anc, int &maxn){
        if(!node){
            maxn = 0;
            return;
        }
        int left = INT_MIN, right = INT_MIN;
        solve(node->left, node->val, left);
        solve(node->right, node->val, right);
        int tmp = left > right ? left + 1 : right + 1;
        ans = ans > left + right + 1 ? ans : left + right + 1;
        if(node->val == anc) maxn = tmp;
        else maxn = 0;
    }
};

// Solution 2: another way

class Solution {
public:
    int ans = 0;
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        solve(root, -1001);
        return ans-1;
    }
    
    int solve(TreeNode* node, int anc){
        if(!node) return 0;
        int left = solve(node->left, node->val);
        int right = solve(node->right, node->val);
        ans = ans > left + right + 1 ? ans : left + right + 1;
        if(node->val != anc)
            return 0;
        return max(left, right) + 1;
        
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        int ret = Solution().longestUnivaluePath(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}