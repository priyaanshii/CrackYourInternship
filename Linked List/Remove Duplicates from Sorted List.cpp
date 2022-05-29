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
    ListNode* deleteDuplicates(ListNode* head) {
            
            if(head==NULL||head->next==NULL)  return head;
            if(head->val == head->next->val && head->next->next==NULL)
            {head->next=NULL; return head;}
            ListNode *p=head,*q=p->next;
            while(q->next!=NULL)
            {
                  q=p->next;
                                         // 1->1->2
                    if(p->val==q->val)   // p  q
                    {
                            p->next=q->next;
                    }
                    else
                    p=p->next;
            }
            
            return head;
    }
};
