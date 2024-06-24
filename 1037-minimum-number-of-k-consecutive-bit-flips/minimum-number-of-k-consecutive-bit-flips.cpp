class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        int f=0;
        int ans=0;
        vector<int>isF(n,0);
        for(int i=0;i<n;i++){
            if(i>=k)f^=isF[i-k];
            if(f==nums[i]){
                if(i+k>n)return -1;
                isF[i]=1;
                f^=1;
                ans++;
            }
        }
        return ans;
    }
};