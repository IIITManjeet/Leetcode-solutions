class Solution {
public:
    vector<vector<int>> memo;
    int n;
    int MOD = 1e9 + 7;
    vector<vector<int>> jumps = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    int dp(int remain,int sq){
        if(remain==0)return 1;
        if(memo[remain][sq]!=0)return memo[remain][sq];
        int ans=0;
        for(auto nextsq:jumps[sq]){
            ans=(ans+dp(remain-1,nextsq))%MOD;
        }
        memo[remain][sq]=ans;
        return ans;
    }
    int knightDialer(int n) {
        this->n=n;
        memo=vector(n+1,vector<int>(10,0));
        int ans=0;
        for(int sq=0;sq<10;sq++)
        ans=(ans+dp(n-1,sq))%MOD;
        return ans;
    }
};