
class Solution {
public:
    ListNode* Reverse(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* rest = Reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return rest;
    }
    ListNode* getKthNode(ListNode* temp, int k) {
        k -= 1;
        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;
        while (temp != NULL) {
            ListNode* kThNode = getKthNode(temp, k);
            if (kThNode == NULL) {
                if (prevLast) {
                    prevLast->next = temp;
                }
                break;
            }
            ListNode* nextNode = kThNode->next;
            kThNode->next = NULL;
            ListNode* rev = Reverse(temp);
            if (temp == head) {
                head = kThNode;
            } else {
                prevLast->next = kThNode;
            }
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};
