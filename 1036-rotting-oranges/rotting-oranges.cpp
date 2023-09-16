class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cntFresh = 0;
        queue<pair<pair<int,int>,int>>q;
       int vis[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else vis[i][j]=0;
                if (grid[i][j] == 1) cntFresh++;
            }
        }
        int delRow[4]={-1,0,+1,0};
        int delCol[4]={0,+1,0,-1};
        int time=0;
        int cnt=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            time=max(time,t);
            q.pop();
            for(int i=0;i<4;i++){
                int newR=r+delRow[i];
                int newC=c+delCol[i];
                if(newR>=0 && newC>=0 && newR<n && newC<m && vis[newR][newC]==0 && grid[newR][newC]==1){
                    q.push({{newR,newC},t+1});
                    vis[newR][newC]=2;
                    cnt++;
                }
            }
        }
        if(cnt!=cntFresh)return -1;
        return time;
    }
};