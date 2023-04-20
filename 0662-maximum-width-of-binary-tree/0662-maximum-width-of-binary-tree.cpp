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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode* , long long>> q;
        q.push({root,0});
        int ans=0;
        while(!q.empty())
        {
            int start=q.front().second;
            int end=q.back().second;
            ans=max (ans, end-start+1);
            int cnt=q.size();
            while(cnt--)
            {
                int k=q.front().second;
                TreeNode* r=q.front().first;
                q.pop();
                int ind=k-start;
                if(r->left)
                {
                    q.push({r->left, (long long)2*ind+1});
                }
                if(r->right)
                {
                    q.push({r->right, (long long)2*ind+2});
                }
            }
        }
        return ans;
    }
};