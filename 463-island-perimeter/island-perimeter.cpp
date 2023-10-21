class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int p=0;
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>> vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    q.push({i,j});
                    vis[i][j]=1;
                    break;
                }
            }
        }

        while(!q.empty()){
            int i=q.front().first,j=q.front().second;
            q.pop();

            for(auto dir:dirs){
                int ni=i+dir[0],nj=j+dir[1];

                if(ni>=0 && ni<m && nj>=0 && nj<n){
                    if(!grid[ni][nj]) p++;
                    else if (!vis[ni][nj]){
                        q.push({ni,nj});
                        vis[ni][nj]=1;
                    }
                }
                else{
                    p++;
                }
            }
        }

        return p;
    }
};