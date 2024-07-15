// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        map<int, TreeNode*> mp;
        set<int> child;
        
        for (const auto& node : d) {
            int u = node[0], v = node[1], isL = node[2];
            if (mp.find(u) == mp.end()) {
                mp[u] = new TreeNode(u);
            }
            if (mp.find(v) == mp.end()) {
                mp[v] = new TreeNode(v);
            }
            if (isL) {
                mp[u]->left = mp[v];
            } else {
                mp[u]->right = mp[v];
            }
            child.insert(v);
        }
        
        for (const auto& e : mp) {
            auto& value = e.first;
            auto& r = e.second;
            if (child.find(value) == child.end()) {
                return r;
            }
        }
        
        return nullptr;
    }
};
