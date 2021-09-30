/*
698. Partition to K Equal Sum Subsets
*/

// Solution 1: dfs:

class Solution {
public:
    vector<bool>visited;
    int sum = 0, n;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        for(auto &i: nums) sum += i;
        if(sum % k) return false;
        n = nums.size();
        sum /= k;
        visited.resize(n, false);
        return solve(nums, 0, k, 0);
    }
    bool solve(vector<int>& nums, int start, int k, int cur){
        if(k == 0) return true;
        if(cur == sum)  return solve(nums, 0, k-1, 0);
        if(start >= n) return false;
        
        bool flag = solve(nums, start + 1, k, cur);
        if(flag) return true;
        
        if(visited[start] || cur + nums[start] > sum) return false;
        visited[start] = true;
        flag = solve(nums, start + 1, k, cur + nums[start]);
        visited[start] = false;
        return flag;
    }
};

// Solution 2: dfs for loop

class Solution {
public:
    vector<bool>visited;
    int sum = 0, n;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        for(auto &i: nums) sum += i;
        if(sum % k) return false;
        // sort(nums.begin(), nums.end());
        n = nums.size();
        sum /= k;
        visited.resize(n, false);
        return solve(nums, 0, k, 0);
    }
    bool solve(vector<int>& nums, int start, int k, int cur){
        if(k == 0) return true;
        if(cur == sum)  return solve(nums, 0, k-1, 0);
        
        for(int i=start ; i<n ; i++){
            if(visited[i]) continue;
            
            visited[i] = true;
            if(solve(nums, i + 1, k, cur+nums[i])) return true;
            visited[i] = false;
        }
        return false;
    }
};

// Solution 3: sort to optimize solution 2

class Solution {
public:
    vector<bool>visited;
    int sum = 0, n;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        for(auto &i: nums) sum += i;
        if(sum % k) return false;
        sort(nums.begin(), nums.end());
        n = nums.size();
        sum /= k;
        visited.resize(n, false);
        return solve(nums, 0, k, 0);
    }
    bool solve(vector<int>& nums, int start, int k, int cur){
        if(k == 0) return true;
        if(cur == sum)  return solve(nums, 0, k-1, 0);
        for(int i=start ; i<n ; i++){
            if(nums[i] + cur > sum) break;
            if(visited[i]) continue;
            visited[i] = true;
            if(solve(nums, i + 1, k, cur+nums[i])) return true;
            visited[i] = false;
        }
        return false;
    }
};

// Solution 4: greed storing the large number then check, a bit slow

class Solution {
public:
    static bool cmp(int &a, int &b){
        return a > b;
    }
    vector<int>vec;
    int sum = 0, n;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        for(auto &i: nums) sum += i;
        if(sum % k) return false;
        sort(nums.begin(), nums.end(), cmp);

        n = nums.size();
        sum /= k;
        vec.resize(k, 0);
        return solve(nums, k, 0);
    }
    bool solve(vector<int>& nums, int k, int start){
        if(start == n){
            for(auto &i: vec) if(i != sum) return false;
            return true;
        }
        
        for(int i=0 ; i<k ; i++){
            if(vec[i] + nums[start] > sum) continue;
            vec[i] += nums[start];
            if(solve(nums, k, start + 1)) return true;
            vec[i] -= nums[start];
        }
        return false;
    }
};