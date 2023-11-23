class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int,vector<int>>m;
        int maxSum=0;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                m[i+j].push_back(nums[i][j]);
                maxSum=max(i+j,maxSum);
            }
        }
        for(int i=0;i<=maxSum;i++){
            for(auto x=m[i].rbegin();x!=m[i].rend();x++){
                ans.push_back(*x);
            }
        }
        return ans;
    }
};