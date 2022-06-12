// Here the node to be deleted is given.


class Solution {
public:
    void deleteNode(ListNode* node) {
        // We just copy the val of next node to the given node.
        node -> val = node -> next -> val;
        // Then we point the given node to the next to next node.
        node -> next = node -> next -> next;
    }
};