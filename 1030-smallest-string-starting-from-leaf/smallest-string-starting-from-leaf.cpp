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
    void dfs(TreeNode* node, std::string &current, std::string &ans) {
        if (!node) return; 
        current.push_back('a' + node->val);
        if (!node->left && !node->right) {
            std::string temp = current;
            std::reverse(temp.begin(), temp.end());
            if (ans.empty() || temp < ans) {
                ans = temp;
            }
        }
        dfs(node->left, current, ans);
        dfs(node->right, current, ans);
        current.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans="";
        string cur="";
        dfs(root,cur,ans);
        return ans;
    }
};