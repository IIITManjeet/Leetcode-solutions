class Solution {
public:
    // bool dfs(int node,vector<vector<int>>& graph,vector<bool>& visit,vector<bool>& inStack,vector<bool>& check){
    //     visit[node]=true;
    //     inStack[node]=true;
    //     check[node]=false;
    //     for(auto neigh:graph[node]){
    //         if(!visit[neigh])
    //         {
    //             if(dfs(neigh,graph,visit,inStack,check))
    //            {
    //                check[node]=false;
    //                return true;
    //            }
    //         }
    //         else if(inStack[neigh])               
    //            {
    //                check[node]=false;
    //                return true;
    //            }
    //     }
    //     check[node]=true;
    //     inStack[node]=false;
    //     return false;
    // }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // int n=graph.size();
        // vector<bool>visit(n),inStack(n),check(n);
        // for(int i=0;i<n;i++){
        //     if(!visit[i])dfs(i,graph,visit,inStack,check);
        // }
        // vector<int>ans;
        // for(int i=0;i<n;i++){
        //     if(check[i]==true)ans.push_back(i);
        // }
        // return ans;
        int n = graph.size();
        vector<int> indegree(n);
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (auto node : graph[i]) {
                adj[node].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<bool> safe(n);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;

            for (auto& neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        vector<int> safeNodes;
        for(int i = 0; i < n; i++) {
            if(safe[i]) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};