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
        int num=0;
public:
    int pathSum(TreeNode* root, int targetSum) {
        
            dfs(root,targetSum);
            return num;
    }
    void dfs(TreeNode* root, int targetSum)
    {
            
            if(root==NULL)
                    return;
            continue_dfs(root,targetSum);
            if(root->left)
                    dfs(root->left,targetSum);
            if(root->right)
                    dfs(root->right,targetSum);
    }
    void continue_dfs(TreeNode* root,long targetSum)
    {
       if(root==NULL) return ;
            targetSum-=root->val;
                if(0==targetSum)
                {
                        num++;
                } 
                        continue_dfs(root->left,targetSum);
                        continue_dfs(root->right,targetSum);
    }
};
