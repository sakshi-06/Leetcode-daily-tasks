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
    TreeNode* del(TreeNode* root, int key)
    {
        if(!root) return nullptr;
        if(root->val < key)
        {
             root->right=del(root->right,key);
        }
        else if(root->val==key)
        {
            if(!root->left || !root->right)
            {
                TreeNode* temp=root;
                root=(root->left?root->left:root->right);
                delete temp;
            }
            else
            {
                TreeNode* temp=root->right;
                while(temp->left)
                {
                    temp=temp->left;
                }
                root->val=temp->val;
                root->right = del(root->right, root->val);
            }
        }
        else
        {
            root->left=del(root->left,key);
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return del(root, key);
    }
};