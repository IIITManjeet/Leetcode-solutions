class Solution {
public:
    const int mod=1e9 + 7;
    // int arrLen;
    // int solve(int cur,int remain,vector<vector<int>>& memo){
    //     if(remain<=0){
    //         if(cur==0)return 1;
    //         return 0;
    //     }
    //     if(memo[cur][remain]!=-1)return memo[cur][remain];
    //     int stay=solve(cur,remain-1,memo);
    //     if (cur> 0) {
    //         stay = (stay + solve(cur - 1, remain - 1,memo)) % mod;
    //     }
        
    //     if (cur < arrLen - 1) {
    //         stay = (stay + solve(cur + 1, remain - 1,memo)) % mod;
    //     }
        
    //     memo[cur][remain] = stay;
    //     return stay;
    // }
    int numWays(int steps, int arrLen) {
        arrLen=min(steps,arrLen);
        vector<vector<int>>memo(arrLen,vector<int>(steps+1,0));
        memo[0][0] = 1;
        for(int remain=1;remain<=steps;remain++){
            for(int cur=arrLen-1;cur>=0;cur--){
                int stay=memo[cur][remain-1];
                if(cur>0)stay=(stay+memo[cur-1][remain-1])%mod;
                if(cur<arrLen-1)stay=(stay+memo[cur+1][remain-1])%mod;
                memo[cur][remain]=stay;
            }
        }
        return memo[0][steps];
    }
};