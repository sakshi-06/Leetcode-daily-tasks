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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return{};
        queue<TreeNode*> q;
        int flag=0;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty())
        {
            vector<int> v;
            int s=q.size();
            while(s--)
            {
                TreeNode* k=q.front();
                q.pop();
                v.push_back(k->val);
                if(k->left) q.push(k->left);
                if(k->right) q.push(k->right);
            }
            if(flag==0)
            {
                ans.push_back(v);
                flag=1;
            }
            else
            {
                reverse(v.begin(), v.end());
                ans.push_back(v);
                flag=0;
            }
        }
        return ans;
    }
};