
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head= new ListNode(-1);
        ListNode* temp=head;
        int carry = 0;
        int val1=0;
        int val2=0;
        while(l1 != NULL || l2!=NULL){
            if(l1!=NULL) val1=l1->val;
            else val1=0;
            if(l2!=NULL) val2=l2->val;
            else val2=0;
            int sum = (val1 + val2) + carry;
            int value= sum % 10;
             carry = sum / 10;
            ListNode* new_ListNode= new ListNode(value);
            temp->next=new_ListNode;
            temp=new_ListNode;
            new_ListNode->next = nullptr;
            if(l1!=NULL)l1=l1->next;
            if(l2!=NULL)l2=l2->next;
        }
        if(carry==1){
            ListNode* new_ListNode= new ListNode(1);
            temp->next=new_ListNode;
            temp=new_ListNode;
            new_ListNode->next = nullptr;
        }
        return head->next;
    }
};