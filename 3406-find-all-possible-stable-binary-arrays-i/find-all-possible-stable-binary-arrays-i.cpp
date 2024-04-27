class Solution {
public:
    int mod=1000000007;
    
    int helper(int zero, int one, int pre, int remain, int limit,vector<vector<vector<vector<int>>>>&dp)
    {
        if(remain<0 || zero<0 || one<0) return 0;
        if(zero==0 && one==0) return 1;
        
        int result=0;
        if(dp[zero][one][pre][remain]!=-1)
        {
            return dp[zero][one][pre][remain];
        }
        
        if(pre==2)
        {
            result=helper(zero,one-1,1,limit-1, limit,dp)%mod;
            result+=helper(zero-1,one,0,limit-1, limit,dp)%mod;
        }
        else if(pre==1)
        {
            result=helper(zero,one-1,1,remain-1, limit,dp)%mod;
            result+=helper(zero-1,one,0,limit-1, limit,dp)%mod;
        }
        else
        {
            result=helper(zero-1,one,0,remain-1, limit,dp)%mod;
            result+=helper(zero,one-1,1,limit-1, limit,dp)%mod;
        }
        return dp[zero][one][pre][remain]=result%mod;
    }
    
    // int dp[201][201][3][201];
    int numberOfStableArrays(int zero, int one, int limit) {
        
        vector<vector<vector<vector<int>>>>dp(zero+1,vector<vector<vector<int>>>(one+1, vector<vector<int>>(3,vector<int>(limit+1,-1))));
        return helper(zero, one, 2, limit, limit,dp);
        
    }
};