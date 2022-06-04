/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
        void parent_tracker(TreeNode *root,unordered_map<TreeNode *,TreeNode*>&p_tk)
        {
                queue<TreeNode *>q;
                q.push(root);
                while(!q.empty())
                {
                        TreeNode *cur=q.front();
                        q.pop();
                        if(cur->left)
                        {
                             p_tk[cur->left]=cur;
                             q.push(cur->left);
                        }
                        if(cur->right)
                        {
                             p_tk[cur->right]=cur;
                             q.push(cur->right);
                        }
                }
        }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *,TreeNode*>p_tk;
            parent_tracker(root,p_tk);
            
            queue<TreeNode *>q;
            unordered_map<TreeNode *,bool>vis;
            q.push(target);
            vis[target]=true;
            int cur_level=0;
            
            while(!q.empty())
            {
                    int s=q.size();
                    if(cur_level==k) break;
                    cur_level++;
                    
                    for(int i=0;i<s;i++)
                    {
                            TreeNode *n=q.front();
                            q.pop();
                            if(n->left && vis[n->left]==false)
                            {      
                                    q.push(n->left);
                                    vis[n->left]=true;
                            }
                            if(n->right && !vis[n->right])
                            {      
                                    q.push(n->right);
                                    vis[n->right]=true;
                            }
                             if(p_tk[n] && !vis[p_tk[n]])
                             {
                                    q.push(p_tk[n]);
                                    vis[p_tk[n]] = true;
                             }
                    }
            }
            
            vector<int>ans;
            
            while(!q.empty())
            {
                    TreeNode *p=q.front();
                      q.pop();
                    ans.push_back(p->val);
                  
            }
            
            return ans;
    }
};
