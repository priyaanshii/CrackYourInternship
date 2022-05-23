//aproach 1 - level order traversal
class Solution {
public:
         
        int rangeSumBST(TreeNode* root, int low, int high) {
                int sum=0;
                queue<TreeNode *>q;
                vector<vector<int>>ans;
                
                q.push(root);
                
                while(!q.empty())
                {
                        vector<int>level;
                        int s=q.size();
                        for(int i=0;i<s;i++)
                        {
                                TreeNode* node=q.front();
                                q.pop();
                                
                                
                                if(node->left!=NULL) 
                                        q.push(node->left);
                                if(node->right!=NULL) 
                                        q.push(node->right);
                                level.push_back(node->val);
                        }
                        ans.push_back(level);
                }
                for(auto i : ans)
                {
                        for(auto j : i)
                        {
                                if(j<=high && j>=low)
                                        sum=sum + j;
                        }
                }
            return sum;
    }
};
//approach 2 - inorder traversal
class Solution {
public:
         int sum=0;
        int inorder(TreeNode *node ,int low,int high)
        {
                if(node==NULL)
                        return 0;
                inorder(node->left,low,high);
                if(node->val>=low && node->val<=high)
                        sum=sum+node->val;
                inorder(node->right,low,high);
                return sum;
        }
        int rangeSumBST(TreeNode* root, int low, int high) {
               
                return inorder(root,low,high);
    }
};
