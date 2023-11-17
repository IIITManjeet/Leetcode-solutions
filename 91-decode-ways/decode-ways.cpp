class Solution {
public:
    int solve(vector<int>& dp,string s,int i){
        if(i==s.size())return 1;
        if(dp[i]!=-1)return dp[i];
        int res=0;
        if(s[i]!='0')res+=solve(dp,s,i+1);
        if(i+1<s.size() && (s[i]=='1'||s[i]=='2' && s[i+1]<'7'))
        res+=solve(dp,s,i+2);
        return dp[i]=res;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        return solve(dp,s,0);   
    }
};