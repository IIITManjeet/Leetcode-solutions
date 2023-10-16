class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<double>prev(m+1,0),curr(m+1,0);
        int i,j;
    
        prev[0]=curr[0]=1;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    curr[j]=prev[j-1]+prev[j];
                    
                }
                else
                    curr[j]=prev[j];
            }
            
            prev=curr;
        }

        return prev[m];
    }
};