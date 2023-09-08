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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size())return NULL;
        unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++)m[inorder[i]]=i;
        return buildTreeNew(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,m);
    }
    TreeNode* buildTreeNew(vector<int>& inorder,int inS,int inE,vector<int>& postorder,int posS,int posE,unordered_map<int,int>& m){
        if(posS>posE || inS>inE)return NULL;
        TreeNode* root=new TreeNode(postorder[posE]);
        int inRoot=m[postorder[posE]];
        int numLeft=inRoot-inS;
        root->left=buildTreeNew(inorder,inS,inRoot-1,postorder,posS,posS+numLeft-1,m);
        root->right=buildTreeNew(inorder,inRoot+1,inE,postorder,posS+numLeft,posE-1,m);
        return root;
    }
};