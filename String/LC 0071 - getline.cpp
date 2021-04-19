/*
71. Simplify Path
*/

class Solution {
public:
    string simplifyPath(string path) {
        vector<string>V;
        stringstream ss(path);
        string cur;
        while(getline(ss, cur, '/')){
            if(cur == "." || cur == "")
                continue;
            if(cur == ".."){
                if(!V.empty())
                    V.pop_back();
            }
            else{
                V.push_back(cur);
            }
        }
        cur.clear();
        for(int i=0; i<V.size() ; i++){
            cur += '/' + V[i];
        }
        if(cur == "")
            return "/";
        return cur;
    }
};