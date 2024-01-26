class Solution {
    int dp[50][50][51];
    vector<pair<int,int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
    int mod=1e9+7;
public:
    int f(int stR,int stC,int mm,int n,int m){
        if(stR>=n || stR<0 || stC>=m || stC<0)return 1;
        if(mm==0)return 0;
        int ans=0;
        if(dp[stR][stC][mm]!=-1)return dp[stR][stC][mm];
        for(int i=0;i<4;i++){
            int newR=stR+dir[i].first;
            int newC=stC+dir[i].second;
            ans=(ans+f(newR,newC,mm-1,n,m))%mod;
        }
        return dp[stR][stC][mm]=ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i][j][0]=0;
            }
        }
        return f(startRow,startColumn,maxMove,m,n);
    }
};