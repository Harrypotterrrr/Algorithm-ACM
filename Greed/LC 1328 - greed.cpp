/*
1328. Break a Palindrome
*/

class Solution {
public:
    string breakPalindrome(string palindrome) {
        string ans;
        int left = 0, right = palindrome.size()-1;
        while(left < palindrome.size()){
            if(right != left && (palindrome[left] != 'a' || left == palindrome.size() - 1)){
                ans += findChar(palindrome[left]);
                break;
            }
            ans += palindrome[left++];
            right--;
        }
        if(left++ >= palindrome.size())
            return "";
        ans += palindrome.substr(left);
        return ans;
    }
    
    char findChar(char c){
        char cc;
        for(cc='a' ; cc<='z' ; cc++)
            if(c != cc)
                break;
        return cc;
    }
};