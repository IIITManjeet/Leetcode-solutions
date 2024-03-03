class Solution {
public:
    // Modified DFS function with memoization
    int dfs(int ind, map<int,vector<int>>& gr, vector<int>& sol, vector<int>& quiet){
        // If the solution for this person is already calculated, return it
        if(sol[ind] != -1) return sol[ind];
        
        int minPos = ind, minQ = quiet[ind];
        for(int neigh : gr[ind]){
            int in = dfs(neigh, gr, sol, quiet);
            if(quiet[in] < minQ){
                minPos = in;
                minQ = quiet[in];
            }
        }
        // Store the result in the solution array and return it
        sol[ind] = minPos;
        return minPos;
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        map<int,vector<int>> gr;
        for(auto it : richer){
            gr[it[1]].push_back(it[0]); // Reversed the direction of edges
        }
        
        vector<int> sol(n, -1);
        for(int i = 0; i < n; i++){
            dfs(i, gr, sol, quiet);
        }
        return sol;
    }
};
