class Solution {
public:
    int f(vector<vector<int>>& grid,int x,int y){
        int val=0;
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++)val=max(val,grid[i][j]);
        }
        return val;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>ans(n-2,vector<int>(n-2,0));
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                ans[i][j]=f(grid,i,j);
            }
        }
        return ans;
    }
};