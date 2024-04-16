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

    void addNode(TreeNode *root, int val, int depth, int curDep) {
        if (root == NULL) {
            return ;
        }

        if (curDep + 1 == depth) {
            TreeNode *ltemp = root->left;
            TreeNode *rtemp = root->right;

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);

            if (ltemp) {
                root->left->left = ltemp;
            }

            if (rtemp) {
                root->right->right = rtemp;
            }
            return;
        }

        addNode(root->left, val, depth, curDep+1);
        addNode(root->right, val, depth, curDep+1);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (root == NULL) {
            if (depth == 1) {
                return new TreeNode(val);
            }

            return NULL;
        }

        if (depth == 1) {
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        int curDepth = 1;
        addNode(root, val, depth, curDepth);
        return root;
    }
};