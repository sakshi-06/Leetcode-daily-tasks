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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newhead = new TreeNode(val);
            newhead->left = root;
            return newhead;
        }
        int lvl = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            lvl++;
            if(lvl == depth-1) break;
            int n=q.size();
            while(n--){
                auto it = q.front();
                q.pop();
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
        }
        int n = q.size();
        while(n--){
            auto node = q.front();
            q.pop();
            TreeNode*temp = new TreeNode(val);
            TreeNode*temp1 = new TreeNode(val);
            temp->left=node->left;
            temp1->right=node->right;
            node->left=temp;
            node->right=temp1;
        }
        return root;
    }
};