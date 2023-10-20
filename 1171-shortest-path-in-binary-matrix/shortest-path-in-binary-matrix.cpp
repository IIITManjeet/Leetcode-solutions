class Solution {
public:
    int dy[8] = {1,-1,0,0,1,1,-1,-1};
    int dx[8] = {0,0,1,-1,1,-1,1,-1};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] || grid.back().back()) return -1;
        int n=grid.size();
        int m=grid[0].size();
        auto isSafe=[&](int x,int y){
            return x>=0 && x<n && y>=0 && y<m;
        };
        // queue<pair<int,pair<int,int>>>q;
        // vector<pair<int,int>>adj;
        // for(int i=0;i<n;i++){
        //     adj[grid[i][0]].push_back({grid[i][1],grid[i][2]});
        //     adj[grid[i][1]].push_back({grid[i][0],grid[i][2]});
        // }
        // q.push({0,})
        if(n==0 || m==0 || grid[0][0]!=0)return -1;
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=1;
        int level=0;
        while(!q.empty()){
            int N=q.size();
            for(int i=0;i<N;i++){
                auto curr=q.front();
                int row=curr.first;
                int col=curr.second;
                if(row==n-1 && col==m-1)return level+1;
                q.pop();
                for(int i=0;i<8;i++){
                    int newRow=row+dy[i];
                    int newCol=col+dx[i];
                    if(isSafe(newRow,newCol)&&grid[newRow][newCol]==0){
                        q.push({newRow,newCol});
                        grid[newRow][newCol]=1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};