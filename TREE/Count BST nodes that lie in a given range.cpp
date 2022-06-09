//Function to count number of nodes in BST that lie in the given range.
class Solution{
public:
    int getCount(Node *root, int l, int h)
    {
        int ans=0;
      // your code goes here 
      stack<Node*>st;
            Node *n=root;
            
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
                            if(n->data>=l && n->data<=h)  ans++;
                            n=n->right;
                            
                    }
            }
            
            return ans;
    }
};
