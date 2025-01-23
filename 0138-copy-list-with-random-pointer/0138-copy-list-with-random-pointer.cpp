/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        unordered_map<Node*, Node*> node_map;

        Node* temp = head;

        while (temp != NULL) {
            node_map[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;
        while (temp != NULL) {
            node_map[temp]->next = node_map[temp->next];
            node_map[temp]->random = node_map[temp->random];
            temp = temp->next;
        }

        return node_map[head];
    }
};