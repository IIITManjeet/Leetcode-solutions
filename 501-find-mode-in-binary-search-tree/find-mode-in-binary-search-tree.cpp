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
    void count(TreeNode* root,unordered_map<int, int>& pq){
        if(root==NULL)return;
        pq[root->val]++;
        count(root->left,pq);
        count(root->right,pq);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> pq;
        count(root,pq);
        vector<int>ans;
        int maxVal=INT_MIN;
        for(auto it:pq){
            maxVal=max(it.second,maxVal);
        }
        for(auto it:pq){
            if(it.second==maxVal)ans.push_back(it.first);
        }
        return ans;
    }
};