class Solution {
public:
    long long helper(string& s1,int i,string& s2,int j,vector<vector<int>>& dp){
         if(i==s1.size() && j==s2.size())return 0;
        if(i==s1.size()){
            int d=0;
            for(int k=j;k<s2.size();k++){
                d += (int)s2[k];
            }
            return d;
        }
        if(j==s2.size()){
            int d=0;
            for(int k=i;k<s1.size();k++){
                d += (int)s1[k];
            }
            return d;
        }
        if(dp[i][j]!=0)return dp[i][j];
        long long ans=INT_MAX;
        if(s1[i]==s2[j]){
            ans=helper(s1,i+1,s2,j+1,dp);
        }
        else{
            ans = min(ans, s1[i] + helper(s1,i+1,s2,j,dp));
            ans = min(ans, s2[j] + helper(s1,i,s2,j+1,dp));
        }
        return dp[i][j] = ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        return helper(s1,0,s2,0,dp);
    }
};