/*
11. Container With Most Water

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/

#include "../include/include.h"

class Solution {
public:
    int maxArea_bruceForce(vector<int>& height) {
        int len = height.size();
        int maxn = 0, tmp;
        for(int i=0 ; i<len-1 ; i++){
            for(int j=i+1 ; j<len ; j++){
                int tmp = (j - i) *min(height[i], height[j]);
                if(tmp > maxn)
                    maxn = tmp;
            }
        }
        return maxn;
    }
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxn = 0, tmp;
        
        while(left < right){
            tmp = (right - left) * min(height[right], height[left]);
            if(maxn < tmp)
                maxn = tmp;
            if(height[right] < height[left])
                right --;
            else
                left ++;
        }
        return maxn;
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

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> height = stringToIntegerVector(line);
        
        int ret = Solution().maxArea(height);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}