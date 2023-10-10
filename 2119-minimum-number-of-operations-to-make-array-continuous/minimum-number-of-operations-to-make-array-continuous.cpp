class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=n;
        unordered_map<int,int>mp;
        for(auto it:nums)mp[it]++;
        vector<int>unique;
        for(auto it:mp){
            unique.push_back(it.first);
        }
        sort(unique.begin(),unique.end());
        int j=0;
        int m=unique.size();
        for (int i = 0; i < m; i++) {
            while (j < m && unique[j] < unique[i] + n) {
                j++;
            }
            ans = min(ans, n - j + i);
        }
        return ans;
    }
};