/************************************************
Problem: 		900. RLE Iterator
Algorithm: 		Design, Array
Difficulty: 	*
Importance:		*
Remark:			
*************************************************/

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */

// Solution 1:

class RLEIterator {
    
    vector<pair<int, int>> vec; // val, k
    pair<int, int> it_id; // vec_id, k
    int vec_len;
public:
    
    RLEIterator(vector<int>& encoding) {
        int n = encoding.size();
        int pre = -1;
        for(int i=0 ; i<n ; i+=2){
            int cur = encoding[i+1];
            int k = encoding[i];
            if(pre == cur)
                vec.back().second += k;
            else
                vec.push_back({cur, k});
            pre = cur;
        }
        vec_len = vec.size();
        it_id = {0, -1};
    }
    
    int next(int n) {
        
        while(it_id.first < vec_len && n >= vec[it_id.first].second - it_id.second){
            n -= vec[it_id.first].second - it_id.second;
            it_id.first++;
            it_id.second = 0;
        }
        if(it_id.first >= vec_len) return -1;
        if(n) it_id.second += n;
        return vec[it_id.first].first;
    }
};

// Solution 2: inplace

class RLEIterator {
    
    vector<int> vec; // val, k
    int id;
    int vec_len;
public:
    
    RLEIterator(vector<int>& encoding) :vec(encoding){
        vec_len = encoding.size();
        id = 0;
    }
    
    int next(int n) {
        while(n && id < vec_len){
            if(n <= vec[id]){
                vec[id] -= n;
                return vec[id+1];
            }
            else{
                n -= vec[id];
                id+=2;
            }
        }
        if(id >= vec_len) return -1;
        return vec[id+1];
    }
};
