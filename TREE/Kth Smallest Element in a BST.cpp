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
// ------------ITERATIVE-APPROACH----------------
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
            stack<TreeNode*>st;
            TreeNode *n=root;
            
            while(true)
            {
                    if(n!=NULL)
                    {
                        st.push(n);
                            n=n->left;
                    }
                    else
                    {
                            if(st.empty()==true)  break;
                            n=st.top();
                            st.pop();
                            ans.push_back(n->val);
                            n=n->right;
                            
                    }
            }
            return ans[k-1];
    }
};
