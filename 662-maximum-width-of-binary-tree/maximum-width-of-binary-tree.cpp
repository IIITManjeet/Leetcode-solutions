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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        
        int max_width = 1;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            int levelSize=q.size();
            int start=q.front().second;
            int end=q.back().second;
            max_width = max(max_width, end - start + 1);
            for (int i = 0; i < levelSize; ++i) {
            auto node_index_pair = q.front();
                TreeNode* node = node_index_pair.first;
                int node_index = node_index_pair.second - start;
                q.pop();
                
                if (node->left != nullptr) {
                    q.push({node->left, 2LL * node_index + 1});
                }
                
                if (node->right != nullptr) {
                    q.push({node->right, 2LL * node_index + 2});
                }
        }
        }
        return max_width;
    }
};