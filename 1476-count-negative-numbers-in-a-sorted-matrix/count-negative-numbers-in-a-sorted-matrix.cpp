class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int totalNegativeElementCount = 0;
        for(int i=0; i<n; i++){
            int negativeElementCount = 0;
            int low = 0;
            int high = m-1;
            while(low <= high){
                int mid = (low + high) >> 1;
                if(grid[i][mid] < 0){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            negativeElementCount = m - low;
            totalNegativeElementCount += negativeElementCount;
        }
        return totalNegativeElementCount;
    }
};