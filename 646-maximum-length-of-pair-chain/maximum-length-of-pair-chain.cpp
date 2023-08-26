class Solution {
public:
    int longest(int i,vector<vector<int>>& pairs,int& n,vector<int>& dp){
        if(dp[i]!=0)return dp[i];
        dp[i]=1;
        for(int j=i+1;j<n;j++){
            if(pairs[i][1]<pairs[j][0]){
                dp[i]=max(dp[i],1+longest(j,pairs,n,dp));
            }
        }
        return dp[i];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<int>dp(n);
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,longest(i,pairs,n,dp));
        }
        return ans;
    }
};