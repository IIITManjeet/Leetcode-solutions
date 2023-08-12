class Solution {
public:
bool isValid(int i, int j,vector<vector<int>> &obstacleGrid){
        if(i < 0 || i >= obstacleGrid.size() || j < 0  || j >= obstacleGrid[i].size())
        return false;
        return true;
    }
    int solve(vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp,int i,int j){
        int ans=0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(i==0 && j==0)return 1;
if(obstacleGrid[i][j] != 1){
        if(isValid(i,j-1,obstacleGrid) && isValid(i-1,j,obstacleGrid) && obstacleGrid[i-1][j] != 1 && obstacleGrid[i][j-1] != 1){
        ans = max(ans, solve(obstacleGrid,dp,i,j-1)+solve(obstacleGrid,dp,i-1,j));
        }
        if(isValid(i,j-1,obstacleGrid) && obstacleGrid[i][j-1] != 1){
        ans = max(ans, solve(obstacleGrid,dp,i,j-1));
        }
        if(isValid(i-1,j,obstacleGrid) && obstacleGrid[i-1][j] != 1){
        ans = max(ans,solve(obstacleGrid,dp,i-1,j));
        }
        }
        return dp[i][j] = ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        if(obstacleGrid[0][0]==1)return 0;
        if(n ==1 && m == 1) return 1;
        return solve(obstacleGrid,dp,m-1,n-1);
    }
};