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
    TreeNode* solve(vector<int>& preorder, int& preIndex,int start, int end, unordered_map<int,int>& mp){
        if(start > end || preIndex >= preorder.size())
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        if(preIndex >= preorder.size() || start == end)
            return root;
        int pos = mp[preorder[preIndex]];;
        
        root->left = solve(preorder, preIndex,start, pos,mp);
        root->right = solve(preorder,preIndex, pos + 1, end - 1,mp);
        
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
         if (postorder.size() == 0) {
        return nullptr;
    }
        unordered_map<int,int>mp;
        for(int i=0;i<postorder.size();i++){
            mp[postorder[i]]=i;
        }
        int preIndex=0;
        int start=0;
        int end=preorder.size()-1;
        return solve(preorder,preIndex,start,end,mp);
    }
};