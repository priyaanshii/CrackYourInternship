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
    int getDecimalValue(ListNode* head) {
       if(head==NULL) return 0;
            int s=0;
            ListNode *temp=head;
            while(temp!=NULL)
            {
                    temp=temp->next;
                    s++;
            }
            int ans=0;
            temp=head;
            for(int i=s-1;i>=0;i--)
            {
                    ans = ans + (pow(2,i)*temp->val);
                    temp=temp->next;
            }
            return ans;
    }
};
