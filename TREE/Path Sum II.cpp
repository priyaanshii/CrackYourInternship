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
    vector<vector<int>>ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>a;
            pathSum(root,targetSum,a);
            return ans;
    }
    void pathSum(TreeNode* root, int targetSum, vector<int>&a)
    {
       if(root==NULL) return ;
            a.push_back(root->val);
                if(root->left == NULL && root->right == NULL &&  root->val==targetSum)
                {
                        ans.push_back(a);
                } 
                    else
                    {
                        pathSum(root->left,targetSum-root->val,a);
                        pathSum(root->right,targetSum-root->val,a);
                    }
            
        a.pop_back();
    }
};
