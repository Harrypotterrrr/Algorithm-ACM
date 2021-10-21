/*
68. Text Justification
String, Parsing
*
*/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ans, line;
        int left_width = maxWidth, str_len = 0;
        for(auto &ss : words){
            if(line.size() && left_width - int(ss.size() + 1) < 0){
                push_string(ans, line, maxWidth, str_len);
                left_width = maxWidth;
                str_len = 0;
                line.clear();
            }
            line.push_back(ss);
            str_len += ss.size();
            left_width = left_width - int(ss.size()) - (left_width == maxWidth ? 0 : 1);
        }
        if(line.size()){
            push_string(ans, line, maxWidth, str_len, true);
        }
        return ans;
    }
    
    void push_string(vector<string>& ans, vector<string>& line, const int maxWidth, const int str_len, bool last_line=false){
        if(last_line){
            string cur_str = "";
            for(auto &i: line) 
                cur_str += i + " ";
            cur_str.resize(maxWidth, ' ');
            ans.push_back(cur_str);
        }
        else{
            if(line.size() == 1){
                string left_str(maxWidth - str_len, ' ');
                ans.push_back(line[0] + left_str);
            }
            else{
                string cur_str = "";
                int inter_len = (maxWidth - str_len) / (line.size() - 1);
                int left_len = maxWidth - str_len - inter_len * (line.size() - 1);
                string space_str(inter_len, ' ');
                for(int i=0 ; i<line.size()-1 ; i++)
                    cur_str += line[i] + space_str + (left_len-- > 0 ? " " : "");
                cur_str += line.back();
                ans.push_back(cur_str);
            }
        }
    }
};