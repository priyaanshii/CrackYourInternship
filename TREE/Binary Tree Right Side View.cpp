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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
            if(root==NULL) return res;
            recursion(root,res,0);
            return res;
    }
        void recursion(TreeNode* root,vector<int>&res,int level)
        {
                if(root==NULL)
                        return ;
                
                if(level==res.size())
                {
                        res.push_back(root->val);
                }
                recursion(root->right,res,level+1);
                recursion(root->left,res,level+1);
        }
};
