//approach 1
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
    int countNodes(TreeNode* root) {
            int c=0;
        inorder(root,c);
            return c;
    }
    void inorder(TreeNode* root,int &c)
    {
            if(root==NULL)
                    return ;
            
            c++;
            inorder(root->left,c);
            inorder(root->right,c);
    }
        
};
//************************************************************************************************************
//appraoch 2
**
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
    int countNodes(TreeNode* root) {
          if(root==NULL)
                  return 0;
            
            int lh = leftHeight(root);
            int rh = rightHeight(root);
            
            if(lh==rh) return pow(2,lh)-1;
            
            return 1+countNodes(root->left)+countNodes(root->right);
            
    }
        int leftHeight(TreeNode *root)
        {
                int h=0;
                while(root)
                {
                        h++;
                        root=root->left;
                }
                return h;
        }
        int rightHeight(TreeNode *root)
        {
                int h=0;
                while(root)
                {
                        h++;
                        root=root->right;
                }
                return h;
        }
        
};
