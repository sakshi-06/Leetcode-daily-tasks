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
    vector<int> v;
    void inorder(TreeNode* root)
    {
        if(!root) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
        return;
    }
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        int ans=INT_MAX;
        for(int i=0;i<v.size()-1;i++)
        {
            ans=min(ans,v[i+1]-v[i]);
        }
        return ans;
    }
};