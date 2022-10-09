//------------------------------method 1------------------------- //
//tc - O(n)  ,  Sc - (n)
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
        vector<int>vec;
        void inorder(TreeNode *root)
        {
                if(root==NULL)
                        return ;
                
                inorder(root->left);
                vec.push_back(root->val);
                inorder(root->right);
        }
    bool findTarget(TreeNode* root, int k) {
            
            if(root->left==NULL && root->right==NULL) 
            return false;

            inorder(root);
            
            int i=0;
            int j=vec.size()-1;
                        
            while(i<j)
            {
                    int val = vec[i] + vec[j];
                    
                    if(val==k)
                            return true;
                    
                    else
                    {
                            if(val<k)
                            {
                                    i++;
                            }
                            else
                            {
                                    j--;
                            }
                    }
            }
            return false;
    }

};
//---------------------Method 2--------------------------//
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
    map<int,int>mp;
    bool findTarget(TreeNode* root, int k) {
            if(root==NULL)
                    return false;
            
            if(mp[k-root->val]>0)
                    return true;
            
            mp[root->val]++;
            return findTarget(root->left,k) || findTarget(root->right,k);
    }
};
