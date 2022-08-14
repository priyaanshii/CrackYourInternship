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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
       return solve(root1,root2);
    }
    TreeNode* solve(TreeNode *root1,TreeNode *root2)
    {
            if(root1==NULL && root2==NULL)
                    return NULL;
            if(root1==NULL)
                    return root2;
            if(root2==NULL)
                    return root1;
            TreeNode *newnode = new TreeNode(root1->val + root2->val);
            newnode->left = solve(root1->left,root2->left);
            newnode->right = solve(root1->right,root2->right);
            
            return newnode;
    }
};
