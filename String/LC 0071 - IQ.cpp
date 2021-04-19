/*
71. Simplify Path
*/

class Solution {
public:
    string simplifyPath(string path) {
        vector<string>V;
        int start, end;
        string cur;
        for(int i=0 ; i<path.size() ; i++){
            while(i<path.size() && path[i] == '/')
                i++;
            start = i;
            if(start >= path.size())
                break;
            while(i<path.size() && path[i] != '/')
                i++;
            end = i;
            cur = path.substr(start, end - start);
            if(cur == ".."){
                 if(!V.empty())
                    V.pop_back();
            }
            else if(cur == ".")
                continue;
            else
                V.push_back(cur);
        }
        string ans;
        if(V.empty())
            return "/";
        for(int i=0 ; i<V.size();i++)
            ans += '/' + V[i];
        return ans;
    }
};
