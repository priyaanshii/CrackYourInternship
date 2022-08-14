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
    int sumNumbers(TreeNode* root) {
            int sum=0;
        solve(root,0,sum);
            return sum;
    }
    void solve(TreeNode *root,int cn,int &sum)
    {
            if(root==NULL)
                    return;
            
            cn = cn *10 + root->val;
                   
            if(root->left==NULL && root->right==NULL)
            {
                    sum = sum + cn;
            }
            solve(root->left,cn,sum);
            solve(root->right,cn,sum);
    }
};
