// Here we have to create 3 pointers and just traverse them together.


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;

        while(curr)
        {
            // next stores curr -> next
            next = curr -> next;
            // curr points to its prev node
            curr -> next = prev;
            // prev becomes curr
            prev = curr;
            // curr becomes next
            curr = next;
        }

        return prev;
    }
};