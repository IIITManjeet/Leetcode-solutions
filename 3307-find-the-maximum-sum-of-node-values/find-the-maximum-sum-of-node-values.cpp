class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& e) {
        int n = nums.size();
        map<int,vector<int>> gr;
        for(auto it : e){
            gr[it[0]].push_back(it[1]);
            gr[it[1]].push_back(it[0]);
        }
        vector<int> index;
        for(int i = 0; i < n; i++){
            if((nums[i] ^ k) > nums[i])
                index.push_back(i);
        }
        int m = index.size();
        if(m % 2){
            long long res = 0;
            long long hash = accumulate(nums.begin(), nums.end(), 0LL);
            for(int i = 0; i < n; i++) {
                find(index.begin(), index.end(), i) == index.end()?res += nums[i]:res += (long long)(nums[i] ^ k);
            }
            for(int i = 0; i < m; i++) {
                long long curr = res - (long long)(nums[index[i]] ^ k) + nums[index[i]];
                hash = max(hash, curr);
            }
            vector<bool> vis(n, false);
            for(auto ind : index)
                vis[ind] = true;
            for(int i = 0; i < n; i++) {
                if(!vis[i]) {
                    long long curr = res - nums[i] + (long long)(nums[i] ^ k);
                    hash = max(hash, curr);
                }
            }
            return hash;
        } else {
            long long res = 0;
            for(int i = 0; i < n; i++) {
                if(find(index.begin(), index.end(), i) == index.end())
                    res += nums[i];
                else
                    res += (long long)(nums[i] ^ k);
            }
            return res;
        }
    }
};
