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
    TreeNode* deleteNode(TreeNode* root, int key) {
      if(root==NULL) return NULL;
        if(root->val>key)
        {
          root->left=deleteNode(root->left,key);
        }
        else if(root->val<key)
        {
          root->right=deleteNode(root->right,key);
        }
        else
        {
          if(root->left==NULL && root->right==NULL)
          {
            root=NULL;
            return root;
          }
          else if(root->left!=NULL && root->right==NULL)
          {
            root=root->left;
            return root;
          }
          else if(root->left==NULL && root->right!=NULL)
          {
            root=root->right;
            return root;
          }
          TreeNode* subs = findNode(root->right);
          TreeNode* temp = NULL;
          temp=root;
          root->val=subs->val;

          root->right=deleteNode(root->right,subs->val);
        }
        return root;
    }
    TreeNode* findNode(TreeNode* node)
    {
      while(node->left!=NULL)
      {
        node=node->left;
      }
      return node;
    }
};
