class Solution {
public:
    vector<string>result;
    void helper(int open,int close, int n,string cur){
        if(cur.size()==n*2){
            result.push_back(cur);
            return;
        }
        if(open<n)helper(open+1,close,n,cur+"(");
        if(close<open)helper(open,close+1,n,cur+")");
    }
    vector<string> generateParenthesis(int n) {
        helper(0,0,n,"");
        return result;
    }
};