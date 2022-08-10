/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
            stack<int>st;
            int count=0;
            ListNode *cur = head;
            while(cur!=NULL)
            {
                    count++;
                    if(count>=left && count<=right)
                    {
                            st.push(cur->val);
                    }
                    
                    cur = cur->next;
            }
            count=0;
            cur=head;
            while(cur!=NULL)
            {
                    count++;
                    if(count>=left && count<=right)
                    {
                            cur->val = st.top();
                            st.pop();
                    }
                    cur=cur->next;
            }
            return head;
    }
};
