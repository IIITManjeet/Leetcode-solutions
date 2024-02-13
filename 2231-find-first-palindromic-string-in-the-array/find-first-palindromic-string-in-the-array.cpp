class Solution {
public:
    bool isPalindrome(string S)
    {
        string P = S;
        reverse(P.begin(), P.end());
        return S==P;
    }
    string firstPalindrome(vector<string>& words) {
        for(string s:words){
            if(isPalindrome(s)){
                return s;
            }
        }
        return "";
    }
};