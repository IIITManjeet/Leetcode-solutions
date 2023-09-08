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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++)m[inorder[i]]=i;
        return  buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,m);
    }
    TreeNode* buildTree(vector<int>& preorder,int preS,int preE, vector<int>& inorder,int inS,int inE,unordered_map<int,int>&m){
        if(preS>preE || inS>inE)return NULL;
        TreeNode* root=new TreeNode(preorder[preS]);
        int inRoot=m[preorder[preS]];
        int numLeft=inRoot-inS;
        root->left=buildTree(preorder,preS+1,preS+numLeft,inorder,inS,inRoot-1,m);
        root->right=buildTree(preorder,preS+numLeft+1,preE,inorder,inRoot+1,inE,m);
        return root;
    }
};