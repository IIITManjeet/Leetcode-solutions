class Solution {
public:
    bool dfs(int source,int destination,vector<vector<int>> &adj,vector<bool>&vis){
        if(source==destination)return true;
        bool res=false;
        vis[source]=true;
        for(int i=0;i<adj[source].size();i++){
            if(!vis[adj[source][i]]){
                res=res || dfs(adj[source][i],destination,adj,vis);
            }
        }
        return res;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n,false);
        return dfs(source,destination,adj,vis);
    }
};