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
    ListNode* reverse(ListNode *head)
    {
            ListNode *prev=NULL,*cur=head,*nxp;
            while(cur!=NULL)
            {
                    nxp=cur->next;
                    cur->next=prev;
                    prev=cur;
                    cur=nxp;
            }
            return prev;
    }
    void reorderList(ListNode* head) {
        ListNode *slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
                slow=slow->next;
                fast=fast->next->next;
        }
        ListNode *first=head,*second;
        second = reverse(slow->next);
        slow->next=NULL;
        
        while(second)
        {
                ListNode *temp1=first->next;
                ListNode *temp2=second->next;
                first->next=second;
                second->next=temp1;
                first=temp1;
                second=temp2;
        }
    }
};
