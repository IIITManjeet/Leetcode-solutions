/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, vector<int>> graph;
    void constructGraph(TreeNode* root) {
        if (!root) return;

        if (root->left) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }

        if (root->right) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }

        constructGraph(root->left);
        constructGraph(root->right);
    }
    int amountOfTime(TreeNode* root, int start) {
        constructGraph(root);
        queue<int>q;
        q.push(start);
        unordered_set<int>vis;
        int min=-1;
        while(!q.empty()){
            ++min;
            for(int i=q.size();i>0;i--){
                int cur=q.front();
                q.pop();
                vis.insert(cur);
                for(int adj:graph[cur]){
                    if(!vis.count(adj)){
                        q.push(adj);
                    }
                }
            }
        }
        return min;
    }
};