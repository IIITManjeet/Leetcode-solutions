class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph,vector<bool>& visit,vector<bool>& inStack,vector<bool>& check){
        visit[node]=true;
        inStack[node]=true;
        check[node]=false;
        for(auto neigh:graph[node]){
            if(!visit[neigh])
            {
                if(dfs(neigh,graph,visit,inStack,check))
               {
                   check[node]=false;
                   return true;
               }
            }
            else if(inStack[neigh])               
               {
                   check[node]=false;
                   return true;
               }
        }
        check[node]=true;
        inStack[node]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool>visit(n),inStack(n),check(n);
        for(int i=0;i<n;i++){
            if(!visit[i])dfs(i,graph,visit,inStack,check);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(check[i]==true)ans.push_back(i);
        }
        return ans;
    }
};