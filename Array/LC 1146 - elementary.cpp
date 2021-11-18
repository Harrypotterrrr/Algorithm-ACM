/************************************************
Problem: 		1146. Snapshot Array
Algorithm: 		STL, Binary Search
Difficulty: 	**
Importance:		*****
Remark:			unordered_map, map, upper_bound, binary tricky search
*************************************************/

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

// Solution 1: linear search with vector unordered_map, time O(n^2)

class SnapshotArray {
public:
    
    vector<unordered_map<int, int>> vec;
    int timestamp;
    
    SnapshotArray(int length) {
        timestamp = 0;
        vec.resize(length, unordered_map<int, int>({{0, 0}}));
    }
    
    void set(int index, int val) {
        vec[index][timestamp] = val;
    }
    
    int snap() {
        return timestamp++;
    }
    
    int get(int index, int snap_id) {
        for(int i=snap_id ; i>=0 ; i--){
            if(vec[index].find(i) != vec[index].end())
                return vec[index][i];
        }
        return 0;
    }
};

// Solution 2: binary search with vector vector: find the first element larger than snap_id, then -1. time: O(nlogn)

class SnapshotArray {
public:
    
    vector<vector<pair<int, int>>> vec;
    int timestamp;
    
    SnapshotArray(int length) {
        timestamp = 0;
        vec.resize(length);
    }
    
    void set(int index, int val) {
        vec[index].push_back({timestamp, val});
    }
    
    int snap() {
        return timestamp++;
    }
    
    int get(int index, int snap_id) {
        auto &cur = vec[index];
        if(!cur.size()) return 0;
        else if(cur[0].first > snap_id) return 0;
        int left = 0, right = cur.size()-1;
        
        // find the id which is the first larger than snap_id
        while(left < right){
            int mid = ((right - left) >> 1) + left;
            if(cur[mid].first > snap_id) right = mid;
            else left = mid + 1;
        }
        if(cur[left].first > snap_id) return cur[left-1].second;
        else return cur[left].second;
    }
};

// Solution 3: binary search with vector vector: find the last element smaller than snap_id + 1. time O(nlogn)

class SnapshotArray {
public:
    
    vector<vector<pair<int, int>>> vec;
    int timestamp;
    
    SnapshotArray(int length) {
        timestamp = 0;
        vec.resize(length);
    }
    
    void set(int index, int val) {
        vec[index].push_back({timestamp, val});
    }
    
    int snap() {
        return timestamp++;
    }
    
    int get(int index, int snap_id) {
        auto &cur = vec[index];
        if(!cur.size()) return 0;
        else if(cur[0].first > snap_id) return 0;
        int left = 0, right = cur.size()-1;
        
        // find the id which is the last smaller than snap_id + 1
        while(left < right){
            int mid = ((right - left) >> 1) + left;
            if(cur[mid].first >= snap_id+1) right = mid - 1;
            else if(left == mid){
                if(cur[right].first < snap_id + 1)
                    left = right;
                break;
            }
            else left = mid;
        }
        return cur[left].second;
    }
};

// Solution 4: binary search with vector vector + upper_bound

class SnapshotArray {
public:
    
    vector<vector<pair<int, int>>> vec;
    int timestamp;
    
    SnapshotArray(int length) {
        timestamp = 0;
        vec.resize(length, {{-1, 0}});
    }
    
    void set(int index, int val) {
        auto &cur = vec[index];
        if(cur.back().first >= timestamp) // strictly, only > is possible
            cur.back().second = val;
        else cur.push_back({timestamp, val});
    }
    
    int snap() {
        return timestamp++;
    }
    
    int get(int index, int snap_id) {
        auto &cur = vec[index];
        auto it = upper_bound(cur.begin(), cur.end(), pair<int, int>(snap_id, INT_MAX));
        return (--it)->second;
    }
};

// Solution 5: STL unordered_map + map + upper_bound

class SnapshotArray {
public:
    
    unordered_map<int, map<int, int>> uM;
    int timestamp;
    
    SnapshotArray(int length) {
        timestamp = 0;
    }
    
    void set(int index, int val) {
        uM[index][timestamp] = val;
    }
    
    int snap() {
        return timestamp++;
    }
    
    int get(int index, int snap_id) {
        auto &cur = uM[index];
        auto it = cur.upper_bound(snap_id);
        return it == cur.begin() ? 0 : (--it)->second;
        // or:
        // return it == begin(cur) ? 0 : prev(it)->second;
    }
};

// Solution 6: STL unordered_map + vector pair + upper_bound

class SnapshotArray {
public:
    
    unordered_map<int , vector<pair<int, int>>> uM;
    int timestamp;
    
    SnapshotArray(int length) {
        timestamp = 0;
        for(int i=0 ; i<length ; i++) uM[i] = {};
    }
    
    void set(int index, int val) {
        auto &cur = uM[index];
        if(cur.size() && cur.back().first >= timestamp)
            cur.back().second = val;
        else cur.push_back({timestamp, val});
    }
    
    int snap() {
        return timestamp++;
    }
    
    int get(int index, int snap_id) {
        auto &cur = uM[index];
        auto it = upper_bound(cur.begin(), cur.end(), pair<int, int>(snap_id, INT_MAX));
        // or: 
        // auto it = upper_bound(cur.begin(), cur.end(), make_pair(snap_id, INT_MAX));
        return it == cur.begin() ? 0 : (--it)->second;
    }
};