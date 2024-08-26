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

//  ListNode* reverseList(ListNode* head) {
//         if(head == NULL || head->next == NULL){
//             return head;}

//         ListNode* prev = NULL;
//         ListNode* curr = head;
//         ListNode* forward = NULL;
//         while(curr!= NULL){
//             forward = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = forward;
//         }
//         head = prev;
//        return head;
//     }
 #include<bits/stdc++.h>
 using namespace std;
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        string s;
        while(head!=NULL){
           s.push_back(head->val);
           head=head->next;
        }
        string temp=s;
        reverse(s.begin(),s.end());
        if(s==temp){
            return true;
        }else return false;
        
    }
};