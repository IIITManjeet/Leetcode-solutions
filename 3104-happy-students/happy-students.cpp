class Solution {
public:
    int countWays(vector<int>& nums) {
        int n=nums.size();
        vector<int>count(n,0);
        for(auto &el:nums)count[el]+=1;
        int psum = 0;
        int res = 1;
        if (count[0] == 0) {
            res++;
        }

        for (int i = 1; i < n; i++) {
            psum += count[i - 1];
            if (psum == i && count[i] == 0) {
                res++;
            }
        }

        return res;
    }
};