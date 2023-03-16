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
    TreeNode* solve(vector<int> &inorder, vector<int> &postorder, int st, int end,int r)
    {
        if(r<0||st>end) return nullptr;
        TreeNode* root=new TreeNode(postorder[r]);
        int index=0;
        for(int i=st;i<=end;i++)
        {
            if(inorder[i]==root->val)
            {
                index=i;
                break;
            }
        }
        root->left=solve(inorder,postorder,st,index-1,r-end+index-1);
        root->right=solve(inorder,postorder,index+1,end,r-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        return solve(inorder,postorder,0,n-1,n-1);
    }
};