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
   int ans=0;
    int calc(vector<int>v)
    {
        int n=0;
        for(int i=0;i<v.size();i++)
        {
            n=n*2+v[i];
        }
        return n;
    }
    void solve(TreeNode* root, vector<int> v)
    {
        if(!root)
        {
            return;
        }
        v.push_back(root->val);
        if(!root->left && !root->right) ans+=calc(v);
        solve(root->left,v);
        solve(root->right,v);
        return ;
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<int> v;
        solve(root,v);
        return ans;
    }
};