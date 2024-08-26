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
    ListNode* sortList(ListNode* head) {
        vector<int> temp;
        ListNode* travel=head;
        while(travel!=NULL){
            temp.push_back(travel->val);
            travel=travel->next;
        }
        sort(temp.begin(),temp.end());
        ListNode* trav=head;
        for(int i=0;i<temp.size();i++){
            trav->val=temp[i];
            trav=trav->next;
        }
        return head;
    }
};