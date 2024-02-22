class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>indegree(n+1,0);
        vector<int>outdegree(n+1,0);
        for(vector<int> it:trust){
            indegree[it[1]]++;
            outdegree[it[0]]++;
        }
        int ans=-1;
        for(int i=0;i<=n;i++){
            if(indegree[i]==n-1 && outdegree[i]==0){
                ans=i;
            }
        }
        return ans;
    }
};