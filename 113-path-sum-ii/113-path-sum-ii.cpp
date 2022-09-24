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
    vector<vector<int>> ans;
    void solve(TreeNode* root, int sum,vector<int> &temp)
    {
        if(!root) return;
        temp.push_back(root->val);
        if(sum==root->val)
        {
            if(root->left==nullptr && root->right==nullptr)
            {
                ans.push_back(temp);
            }
        }
        
        solve(root->left,sum-root->val, temp);
        solve(root->right, sum-root->val, temp);
        temp.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        solve(root,targetSum,temp);
        return ans;
    }
};