class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        map<int,int>m;
        int n=nums.size();
        for(auto &i:nums) 
        { 
            m[i+k+1]--; 
            m[i-k]++; 
        } 
        int temp=0; 
        int ans=0; 
        for(auto x=m.begin();x!=m.end();x++) 
        { 
            temp+= x->second; 
            ans=max(ans,temp); 
        } 
        return ans; 
    }
};