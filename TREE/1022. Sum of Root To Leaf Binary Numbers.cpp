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
    int sumRootToLeaf(TreeNode* root) {
      vector<int>vec;
      int sum=0;
      helper(root,vec,sum);
      return sum;
    }

    void helper(TreeNode* root,vector<int>&vec,int &sum)
    {
     if (!root) {
            return;
        }

        vec.push_back(root->val);

        if (!root->left && !root->right) {
            sum += binaryToDecimal(vec);
        } else {
            helper(root->left, vec, sum);
            helper(root->right, vec, sum);
        }

        vec.pop_back();
    }

  int binaryToDecimal(const vector<int>& vec) {
        int dec_value = 0;
        int base = 1;
        for (int i = vec.size() - 1; i >= 0; i--) {
            dec_value += vec[i] * base;
            base = base * 2;
        }
        return dec_value;
    }
};
