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
    bool isCousins(TreeNode* root, int x, int y) {
        vector<int>parents(2);
        vector<int>levels(2);
        TreeNode* nn = new TreeNode(-1);
        findParentsandLevel(root,x,y,parents,levels,0,nn);
        return parents[0]!=parents[1] && levels[0]==levels[1];
    }

    void findParentsandLevel(TreeNode* root, int x, int y,vector<int>&parents,vector<int>&levels,int currentLevel,TreeNode* currentParent)
    {
      if(root==NULL)
      {
        return;
      }
      if(root->val==x)
      {
        parents[0]=currentParent->val;
        levels[0]=currentLevel;
      }
      if(root->val==y)
      {
        parents[1]=currentParent->val;
        levels[1]=currentLevel;
      }
      findParentsandLevel(root->left,x,y,parents,levels,currentLevel+1,root);
      findParentsandLevel(root->right,x,y,parents,levels,currentLevel+1,root);
    }
};
