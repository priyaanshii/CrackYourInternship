/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int len(ListNode* head){
    ListNode* temp=head;
    int ans=0;
    while(temp){
        ans++;
        temp=temp->next;
    }
    return ans;
}
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode* t1=headA;
        ListNode* t2=headB;
        int l1=len(headA),l2=len(headB);
        if(l1>l2){
            int k=l1-l2;
            while(k){
                t1=t1->next;
                k--;
            }
        }else{
            int k=l2-l1;
            while(k){
                t2=t2->next;
                k--;
            }
        }
        while(t1 and t2){
            if(t1==t2){
                return t1;
            }
            t1=t1->next;
            t2=t2->next;
        }
        return NULL;
    }
};
