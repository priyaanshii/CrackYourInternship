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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>t1;
        vector<int>t2;

        helper(root1,t1);
        helper(root2,t2);

        return isSimilar(t1,t2);
    }
    void helper(TreeNode* root,vector<int>&leafnodes)
    {
      if(!root)
      {
        return;
      }
      if(!root->left && !root->right)
      {
        leafnodes.push_back(root->val);
      }
      helper(root->left,leafnodes);
      helper(root->right,leafnodes);
    }
    bool isSimilar(vector<int>t1,vector<int>t2)
    {
      if(t1.size()!=t2.size())
      return false;

      for(int i=0;i<t1.size();i++)
      {
        if(t1[i]!=t2[i])
        {
          return false;
        }
      }

      return true;
    }
};
