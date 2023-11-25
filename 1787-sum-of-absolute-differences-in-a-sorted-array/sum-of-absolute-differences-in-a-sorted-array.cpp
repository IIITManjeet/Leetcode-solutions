class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n);
        int lt=0;
        int rt=0;
        for(int i=0;i<n;i++)
        {
            rt+=nums[i];
        }
        for(int i=0;i<n;i++)
        {
            res[i]=(nums[i]*i-lt)+(rt-nums[i]*(n-i));
            lt+=nums[i];
            rt-=nums[i];
        }
        return res;
    }
};