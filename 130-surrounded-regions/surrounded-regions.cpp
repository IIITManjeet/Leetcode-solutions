class Solution {
public:
    void solve(vector<vector<char>>& b) {
int m = b.size(), n = b[0].size();
        vector<vector<int>> vis(m, vector<int> (n));
        queue<pair<int, int>> q;

        // First store position of all the O's that are present at the boundary in the queue data structue
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(i==0 || j==0 || i==m-1 || j==n-1){
                    if(b[i][j]=='O'){
                        q.push({i, j});
                        vis[i][j]=1;
                    } 
                }

        // Start BFS traversal and mark all the O's that are connected to these boundary element
        while(!q.empty()){
            auto [r, c] = q.front();
            vis[r][c]=1;
            q.pop();
            for(int x=-1; x<=1; x++){
                for(int y=-1; y<=1; y++){
                    if(x&&y || (x==0 && y==0)) continue;
                    int nrow = r+x, ncol = c+y;
                    if(nrow<0 || ncol<0 || nrow>=m || ncol>=n) continue;
                    if(vis[nrow][ncol] || b[nrow][ncol]=='X') continue;
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        // check which O's are unmarked, that means they are not connected to the boundary element that's why they are unmarked
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j]==0 && b[i][j]=='O') b[i][j] = 'X';
            }
        }

    }
};