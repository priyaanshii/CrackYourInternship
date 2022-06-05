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
    bool isValidBST(TreeNode* root) {
            return isValidBST(root,LONG_MIN ,LONG_MAX);
            
    }
    bool isValidBST(TreeNode *root,long mini,long maxi)
    {
            if(root==NULL)
            return true;
            
            if(root->val >= maxi || root->val <= mini )
                    return false;
            
            bool ls = isValidBST(root->left,mini,root->val);
            bool rs = isValidBST(root->right,root->val,maxi);
            
            return (ls && rs);
    }
};
