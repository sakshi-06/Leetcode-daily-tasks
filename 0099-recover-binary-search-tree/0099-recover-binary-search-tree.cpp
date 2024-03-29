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
    TreeNode* prev=nullptr;
    vector<pair<TreeNode*, TreeNode*>> v;
    void solve(TreeNode* root)
    {
        if(!root) return ;
        solve(root->left);
        //logic
        if(prev && prev->val > root->val)
        {
            v.push_back({prev, root});
        }
        prev=root;
        solve(root->right);
        return ;
    }
    void recoverTree(TreeNode* root) {
        solve(root);
        if(v.size()==1)
        {
            swap(v[0].first->val , v[0].second->val);
        }
        else swap(v[0].first->val, v[1].second->val);
        return;
    }
};