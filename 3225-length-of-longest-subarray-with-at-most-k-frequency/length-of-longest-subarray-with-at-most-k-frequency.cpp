class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i = 0,j = 0,n = nums.size(),ans = INT_MIN;
        map<int,int>mp;
        for(j=0;j<n;j++)
        {
            mp[nums[j]]++;
            if(mp[nums[j]] > k)
            {
                while(mp[nums[j]] > k && i<j)
                {
                    if(mp[nums[i]] != 1){
                        mp[nums[i]]--;i++;
                    }
                    else{
                        mp.erase(nums[i]);i++;
                    }
                }
            }
            ans = max(ans, j-i+1);
        }
        
        return ans;
    }
};