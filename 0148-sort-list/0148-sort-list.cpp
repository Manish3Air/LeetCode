#include<bits/stdc++.h>
class Solution {
public:
ListNode* mergeTwoSortedLinkedLists(ListNode* list1, ListNode* list2) {
    ListNode* dummyListNode = new ListNode(-1);
    ListNode* temp = dummyListNode;
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
       
        temp = temp->next; 
    }    
    if (list1 != nullptr) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }
    return dummyListNode->next;
}
ListNode* findMiddle(ListNode* head){
    
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode* sortLL(ListNode* head){
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* middle = findMiddle(head);
    ListNode* right = middle->next;
    middle->next = nullptr;
    ListNode* left = head;
    left = sortLL(left);
    right = sortLL(right);
    return mergeTwoSortedLinkedLists(left, right);
}
    ListNode* sortList(ListNode* head) {
        return sortLL(head);
    }
};