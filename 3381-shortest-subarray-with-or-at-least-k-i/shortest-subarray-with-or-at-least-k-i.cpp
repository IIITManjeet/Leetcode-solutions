class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int sz=100, n=nums.size();
        for(int x=0; x<n; x++)
        {
            int o=0;
            for(int y=x; y<n; y++)
            {
                o|=nums[y];
                if(o>=k) sz=min(sz,y-x+1);
            }
        }    
        return (sz==100)?-1:sz;
    }
};