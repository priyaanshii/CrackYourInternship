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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
            if(root==NULL) return ans;
            queue<TreeNode *>q;
            bool flag=true;
            q.push(root);
            
            while(!q.empty())
            {
                    int s=q.size();
                    vector<int>level(s);
                    for(int i=0;i<s;i++)
                    {
                            TreeNode *node=q.front();
                            q.pop();
                            
                            if(flag==true) level[i]=node->val;
                            if(flag==false) level[s-1-i]=node->val;
                            if(node->left!=NULL) q.push(node->left);
                            if(node->right!=NULL) q.push(node->right);
                            
                           
                    }
                    
                    if(flag==true) flag=false;
                    else flag=true;
                            ans.push_back(level);
                    
                          
            }
            
            return ans;
    }
};
