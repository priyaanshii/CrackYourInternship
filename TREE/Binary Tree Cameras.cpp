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
        int cam=0;
    int minCameraCover(TreeNode* root) {
        int ans = dfs(root);
            if(ans==-1)
                    return cam+1;
            else 
                    return cam;
    }
        int dfs(TreeNode *root)
        {
                if(root==NULL)
                        return 1;
                int l = dfs(root->left);
                int r = dfs(root->right);
                
                if(l==-1 || r==-1)
                {
                        cam++;
                        return 0;
                }
                if(l==0 || r==0)
                        return 1;
                return -1;
        }
};
