class Solution {
public:
    int dp[51][51][101];
    int solve(int idx,int lis,int lar,int& n,int& m,int& k){
        if(idx==n){
            if(lis==k)return 1;
            else return 0;
        }
        if(dp[idx][lis][lar]!=-1)return dp[idx][lis][lar];
        int ans=0;
        for(int i=1;i<=m;i++){
            if(i>lar)ans+=solve(idx+1,lis+1,i,n,m,k);
            else ans+=solve(idx+1,lis,lar,n,m,k);
            ans=ans%(1000000007);
        }
        return dp[idx][lis][lar]=ans;
    }
    int numOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,n,m,k);
    }
};