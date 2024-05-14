class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int n=0,m=0;

    int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis){
        vis[i][j]=1;
        int val=grid[i][j];
        int cur=0;
        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(ni>=0 && nj>=0 && ni<n && nj<m && !vis[ni][nj] && grid[ni][nj] != 0){
                cur=max(f(ni,nj,grid,vis),cur);
            }
        }
        vis[i][j]=0;
        val+=cur;
        return val;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)if(grid[i][j]==0)vis[i][j]=1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    ans=max(ans, f(i,j,grid,vis));
                }
            }
        }
        return ans;
    }
};
