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
            if(head==NULL || head->next==NULL)
                    return head;
            
            ListNode *cur=head,*prev=NULL,*nxt;
            while(cur!=NULL)
            {
                    nxt=cur->next;
                    cur->next=prev;
                    prev=cur;
                    cur=nxt;
            }
            return prev;
            
    }
    ListNode* findSum(ListNode* l1, ListNode* l2)
    {
            
            if(l1==NULL)
                    return l2;
            if(l2==NULL)
                    return l1;
            ListNode *l3 = new ListNode(0);
            ListNode *head=l3;
            int carry=0,val=0;
            while(l1 && l2)
            {
                    val = l1->val + l2->val + carry;
                    carry = val/10;
                    l3->next = new ListNode(val%10);
                    l1=l1->next;
                    l2=l2->next;
                    l3=l3->next;
            }
            while(l1)
            {
                    val = l1->val + carry;
                    carry = val/10;
                    l3->next = new ListNode(val%10);
                    l1=l1->next;
                    l3=l3->next;
            }
            while(l2)
            {
                    val = l2->val + carry;
                    carry = val/10;
                    l3->next = new ListNode(val%10);
                    l2=l2->next;
                    l3=l3->next;
            }
            if(carry)
            {
                    l3->next = new ListNode(carry);
            }
            return head->next;
    }
        
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *list1 = reverse(l1);
        ListNode *list2 = reverse(l2);
            
        ListNode *list3 = findSum(list1,list2);
            
        return reverse(list3);
            
    }
};
