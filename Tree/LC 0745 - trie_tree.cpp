/************************************************
Problem: 		745. Prefix and Suffix Search
Algorithm: 		Trie Tree
Difficulty: 	****
Importance:		****
Remark:			
*************************************************/


/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */


// Solution 1: Trie tree, TLE. Time O(NL + Q(N + L)) where N is the length of nums, L is the maximum length of the word, Q is the number of Query

class WordFilter {
public:

    struct TrieNode{
        unordered_map<char, TrieNode*> uM;
        vector<int>vec; // store the index from dict
        TrieNode(){}
    };
    
    int n;
    TrieNode *pre, *suf;
    
    WordFilter(vector<string>& words) {
        pre = new TrieNode;
        suf = new TrieNode;
        n = words.size();
        int id = 0;
        for(auto &word: words){
            TrieNode *p = pre, *q = suf;
            int cur_len = word.size();
            for(int i=0 ; i<cur_len ; i++){
                if(p->uM.find(word[i]) == p->uM.end()){
                    TrieNode *new_node = new TrieNode;
                    p->uM[word[i]] = new_node;
                }
                p = p->uM[word[i]];
                p->vec.push_back(id);
                
                if(q->uM.find(word[cur_len-i-1]) == q->uM.end()){
                    TrieNode *new_node = new TrieNode;
                    q->uM[word[cur_len-i-1]] = new_node;
                }
                q = q->uM[word[cur_len-i-1]];
                q->vec.push_back(id);
            }
            id ++;
        }
    }
    
    int f(string prefix, string suffix) {
        int pre_len = prefix.size(), suf_len = suffix.size();
        int i = 0, j = 0;
        TrieNode *p = pre, *q = suf;
        while(i < pre_len && j < suf_len){
            if(p->uM.find(prefix[i]) != p->uM.end()) p = p->uM[prefix[i]];
            else return -1;
            if(q->uM.find(suffix[j]) != q->uM.end()) q = q->uM[suffix[j]];
            else return -1;
            i++; j++;
        }
        while(i < pre_len){
            if(p->uM.find(prefix[i]) != p->uM.end()) p = p->uM[prefix[i]];
            else return -1;
            i++;
        }
        while(j < suf_len){
            if(q->uM.find(suffix[j]) != q->uM.end()) q = q->uM[suffix[j]];
            else return -1;
            j++;
        }
        // find valid index from TrieNode->vec
        i = p->vec.size()-1;
        j = q->vec.size()-1;
        while(i >= 0 && j >= 0 && p->vec[i] != q->vec[j]){
            if(p->vec[i] == q->vec[j]) break;
            if(p->vec[i] > q->vec[j]) i--;
            else j--;
        }
        if(i < 0 || j < 0) return -1;
        else return p->vec[i];
    }
};

// Solution 2: build complete trie-prefix-suffix tree. time: O(NL^2 + QL), space: O(NL^2)

class WordFilter {
public:

    struct TrieNode{
        unordered_map<int, TrieNode*> uM;
        vector<int>vec; // store the index from dict
        TrieNode(){}
    };
    
    int n;
    TrieNode *root;
    
    inline int get_key(char a, char b){
        return 27 * (a == ' ' ? 0 : (a - '`')) + (b == ' ' ? 0 : (b - '`'));
    }
    
    WordFilter(vector<string>& words) {
        root = new TrieNode;
        n = words.size();
        int id = 0, key, cur_len;
        for(auto &word: words){
            TrieNode *cur = root;
            cur_len = word.size();
            for(int i=0 ; i<cur_len ; i++){
                TrieNode *tmp = cur;
                for(int j=i ; j<cur_len ; j++){
                    key = get_key(word[j], ' ');
                    if(tmp->uM.find(key) == tmp->uM.end()){
                        TrieNode *new_node = new TrieNode;
                        tmp->uM[key] = new_node;
                    }
                    tmp = tmp->uM[key];
                    tmp->vec.push_back(id);
                }
                
                tmp = cur;
                for(int j=cur_len-1-i; j>=0 ; j--){
                    key = get_key(' ', word[j]);

                    if(tmp->uM.find(key) == tmp->uM.end()){
                        TrieNode *new_node = new TrieNode;
                        tmp->uM[key] = new_node;
                    }
                    tmp = tmp->uM[key];
                    tmp->vec.push_back(id);
                }
                
                tmp = cur;
                key = get_key(word[i], word[cur_len - 1 - i]);

                if(tmp->uM.find(key) == tmp->uM.end()){
                    TrieNode *new_node = new TrieNode;
                    tmp->uM[key] = new_node;
                }
                tmp = tmp->uM[key];
                tmp->vec.push_back(id);
                cur = tmp;
            }
            id ++;
        }
    }
    
    int f(string prefix, string suffix) {
        int pre_len = prefix.size(), suf_len = suffix.size();
        int i = 0, j = suf_len - 1, key;
        TrieNode *p = root;
        while(i < pre_len && j >= 0){
            key = get_key(prefix[i], suffix[j]);
            if(p->uM.find(key) != p->uM.end()) p = p->uM[key];
            else return -1;
            i++; j--;
        }
        while(i < pre_len){
            key = get_key(prefix[i], ' ');
            if(p->uM.find(key) != p->uM.end()) p = p->uM[key];
            else return -1;
            i++;
        }
        while(j  >= 0){
            key = get_key(' ', suffix[j]);
            if(p->uM.find(key) != p->uM.end()) p = p->uM[key];
            else return -1;
            j--;
        }
        return p->vec.back();
    }
};

// Solution 3: append suffix word to prefix to build trie. time: O(NL^2 + QL), space: O(NL^2)

class WordFilter {
public:

    struct TrieNode{
        unordered_map<char, TrieNode*> uM;
        vector<int>vec; // store the index from dict
        TrieNode(){}
    };
    
    int n;
    TrieNode *root;
    
    WordFilter(vector<string>& words) {
        root = new TrieNode;
        n = words.size();
        int id = 0, cur_len;
        for(auto &word: words){
            // string ss = word + '#' + word;
            TrieNode *cur = root;
            cur_len = word.size();
            string ss;
            
            for(int i=1 ; i<=cur_len ; i++){
                cur = root;
                ss = word.substr(cur_len-i,i) + '#' + word;
                int ss_len = ss.size();
                for(int j=0 ; j<ss_len ; j++){
                    if(cur->uM.find(ss[j]) == cur->uM.end()){
                        TrieNode *new_node = new TrieNode;
                        cur->uM[ss[j]] = new_node;
                    }
                    cur = cur->uM[ss[j]];
                    cur->vec.push_back(id);
                }
            }
            id ++;
        }
    }
    
    int f(string prefix, string suffix) {
        string ss = suffix + '#' + prefix;
        int len = ss.size(), i = 0;
        TrieNode *p = root;
        while(i < len){
            if(p->uM.find(ss[i]) != p->uM.end()) p = p->uM[ss[i]];
            else return -1;
            i++;
        }
        return p->vec.back();
    }
};
