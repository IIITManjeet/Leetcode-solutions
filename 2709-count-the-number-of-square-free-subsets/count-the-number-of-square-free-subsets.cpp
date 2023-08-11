class Solution {
public:
    long long dp[1024];
    vector<int>primes={2,3,5,7,11,13,17,19,23,29};
    int mod=1e9+7;
    int squareFreeSubsets(vector<int>& nums) {
        dp[0]=1;
        for(int x:nums){
            bool flag=0;
            for(int j:primes){
                if(x%(j*j)==0){
                    flag=1;
                    break;
                }
            }
            if(flag){
                continue;
            }
            int mask=0;
            for(int i=0;i<10;i++)
                if((x%primes[i])==0){
                    mask+=(1<<i);
                }
            for(int i=0;i<1024;i++)
                if((i & mask)==mask)
                (dp[i]+=dp[i-mask])%=mod;
        }
        long long ans=0;
        for(int x:dp){
            (ans+=x)%=mod;
        }
        return (ans+mod-1)%mod;
    }
};