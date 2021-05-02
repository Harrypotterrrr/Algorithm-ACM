/*
146. LRU Cache
*/

class LRUCache {
public:
    
    unordered_map<int, list<pair<int, int>>::iterator>M;
    list<pair<int, int>> ll;
    int capacity;
    
    LRUCache(int _capacity) {
        capacity = _capacity;
    }
    
    int get(int key) {
        if(M.find(key) == M.end())
            return -1;
        auto &it = M[key];
        pair<int, int> tmp(it->first, it->second);
        ll.erase(it);
        ll.push_front(tmp);
        M[key] = ll.begin();
        return tmp.second;
    }
    
    void put(int key, int value) {
        auto it = M.find(key);
        if(it != M.end()){
            ll.erase(it->second);
        }
        else if(M.size() == this->capacity){
            M.erase(ll.rbegin()->first);
            ll.pop_back();
        }
        ll.push_front(pair<int, int>(key, value));
        M[key] = ll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


// Solution 2: minor modify by using splice function of list

class LRUCache {
public:
    
    unordered_map<int, list<pair<int, int>>::iterator>M;
    list<pair<int, int>> ll;
    int capacity;
    
    LRUCache(int _capacity) {
        capacity = _capacity;
    }
    
    int get(int key) {
        if(M.find(key) == M.end())
            return -1;
        auto &it = M[key];
        ll.splice(ll.begin(), ll, it);
        return ll.begin()->second;
    }
    
    void put(int key, int value) {
        auto it = M.find(key);
        if(it != M.end()){
            ll.erase(it->second);
        }
        else if(M.size() == this->capacity){
            M.erase(ll.rbegin()->first);
            ll.pop_back();
        }
        ll.push_front(pair<int, int>(key, value));
        M[key] = ll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */