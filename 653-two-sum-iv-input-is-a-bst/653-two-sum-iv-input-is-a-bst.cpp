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
    void solve(TreeNode* root)
    {
        if(!root) return;
        solve(root->left);
        v.push_back(root->val);
        solve(root->right);
        return;
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> mp;
        solve(root);
        for(int i=0;i<v.size();i++)
        {
            if(mp.find(k-v[i])!=mp.end())
            {
                return true;
            }
            mp[v[i]]++;
        }
        return false;
    }
};