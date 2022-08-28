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
    vector<TreeNode* > v;
    void solve(TreeNode* root)
    {
        if(!root) return ;
        v.push_back(root);
        if(root->left)  solve(root->left);
        if(root->right) solve(root->right);
    }        
    void flatten(TreeNode* root) {
        solve(root);
        for(int i=1;i<v.size();i++)
        {
            v[i-1]->right=v[i];
            v[i-1]->left =nullptr;
        }
        return ;
    }
};