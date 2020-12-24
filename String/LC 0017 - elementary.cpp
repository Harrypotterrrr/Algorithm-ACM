// 17. Letter Combinations of a Phone Number

class Solution
{
public:
    string map_table[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> recursion(vector<string> &cur, const int d)
    {
        vector<string> rtn;

        if (cur.size() == 0)
        {
            for (auto j : map_table[d]) {
                rtn.push_back(string(1, j));
            }
        }
        for (auto i : cur)
        {
            for (auto j : map_table[d]) {
                rtn.push_back(i + j);
            }
        }
        return rtn;
    }

    vector<string> letterCombinations(string digits)
    {

        vector<string> rtn;

        for (auto i : digits) {
            rtn = recursion(rtn, int(i - '0'));
        }
        return rtn;
    }
};