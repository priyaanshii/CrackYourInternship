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
        
   /*) bool isLeaf(TreeNode *node)
    {
            if(node->left==NULL && node->right==NULL)
                    return true;
            else 
                    return false;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
   vector<string> ans;
  queue<pair<TreeNode*, string>> q;
  q.emplace(root, "");

  while (!q.empty()) {
    TreeNode* curr_node = q.front().first;
    string curr_str = q.front().second;
    q.pop();

    if (!curr_node->left && !curr_node->right) {  // leaf
      ans.push_back(curr_str + to_string(curr_node->val));
      // the line above assumes previous iterations added an arrow at the end
    } else {
      if (curr_node->left) {
        q.emplace(curr_node->left, curr_str + to_string(curr_node->val) + "->");
      }
      if (curr_node->right) {
        q.emplace(curr_node->right,
                  curr_str + to_string(curr_node->val) + "->");
      }
    }
  }

  return ans;
            
    }*/
        void helper(TreeNode* node, vector<string>& ans, string str) {
  if (!node->left && !node->right) {  
    ans.push_back(str + to_string(node->val));
    return;
  }

  string new_tail = to_string(node->val) + "->";
  if (node->left) helper(node->left, ans, str + new_tail);
  if (node->right) helper(node->right, ans, str + new_tail);
}

vector<string> binaryTreePaths(TreeNode* root) {
  vector<string> ans;
  helper(root, ans, "");

  return ans;
}
};
