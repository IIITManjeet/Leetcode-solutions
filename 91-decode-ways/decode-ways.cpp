class Solution {
public:
    // int solve(vector<int>& dp,string s,int i){
    //     if(i==s.size())return 1;
    //     if(dp[i]!=-1)return dp[i];
    //     int res=0;
    //     if(s[i]!='0')res+=solve(dp,s,i+1);
    //     if(i+1<s.size() && (s[i]=='1'||s[i]=='2' && s[i+1]<'7'))
    //     res+=solve(dp,s,i+2);
    //     return dp[i]=res;
    // }
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n + 1, 0);
   	    dp[0] = 1;
   	    dp[1] = s[0] != '0' ? 1 : 0;
        for (int index = 2; index <= n; index++)
   	    {
   	       	// Single-digit case
   	        if (s[index - 1] != '0')
   	            dp[index] += dp[index - 1];

   	       	// Two-digit case
   	        int twoDigitNum = stoi(s.substr(index - 2, 2));
   	        if (twoDigitNum >= 10 && twoDigitNum <= 26)
   	            dp[index] += dp[index - 2];
   	    }
        return dp[n];
    }
};