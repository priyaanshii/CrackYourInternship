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
TreeNode *constructTree(vector<int> preorder, vector<int> postorder, int preBeg, int preEnd, int postBeg, int postEnd)
{
        if(preEnd < preBeg || postEnd < postBeg || preEnd > preorder.size())
                return NULL;
        
        TreeNode *root = new TreeNode(preorder[preBeg]);
        
        if (preBeg == preEnd)
            return root;
        
        int newPreBeg = preBeg + 1, newPreEnd;
        int newPostBeg = postBeg, newPostEnd;
        
        for(int i=newPostBeg;i<postEnd;i++)
        {
                if(postorder[i]==preorder[newPreBeg])
                {
                        newPostEnd=i;
                        break;
                }
        }
                newPreEnd = newPreBeg + newPostEnd - newPostBeg;

        // Recursively constructing left subtree
root->left = constructTree(preorder, postorder, newPreBeg, newPreEnd, newPostBeg, newPostEnd);
        
	// Recursively constructing the right subtree
root->right = constructTree(preorder, postorder, newPreEnd + 1, preEnd, newPostEnd + 1, postEnd - 1);

        return root;

}

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
      return constructTree(preorder, postorder, 0, preorder.size()-1,0, postorder.size()-1);

    }
};
