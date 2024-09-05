class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum=0;
        for(auto it:rolls)sum+=it;
        int rem=mean*(n+rolls.size())-sum;
        if(rem>6*n or rem<n)return {};
        int div=rem/n;
        int mod=rem%n;
        vector<int>ans(n,div);
        for(int i=0;i<mod;i++)ans[i]++;
        return ans;
    }
};