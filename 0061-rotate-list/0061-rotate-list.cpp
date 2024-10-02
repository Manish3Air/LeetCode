
class Solution {
public:
    ListNode* rotate(ListNode* head, int k,int len){
        int count = 0;
        ListNode* temp  = head;
        ListNode* rothead = NULL;
        while(temp->next!=NULL){
            count++;
            if(count==len-k){
                rothead = temp;
            }
            temp=temp->next;
        }
        temp->next = head;
        ListNode* new_head = rothead->next;
        rothead->next = NULL;
        return new_head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        int len=0;
        ListNode* temp = head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        if(k%len==0) return head;
        else{
            int rot = k%len;
            ListNode* new_head = rotate(head,rot,len);
            return new_head;
        }
    }
};