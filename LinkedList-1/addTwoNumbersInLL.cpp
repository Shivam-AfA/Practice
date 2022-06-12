

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // First we create a new LL.
        ListNode* newList = new ListNode();

        // We define a new node on the head of the LL.
        ListNode* temp = newList;

        // We define carry over integer.
        int carry = 0;
        while(l1 || l2 || carry)
        {
            int sum = 0;

            // We store and add sum of digits in l1 and l2 and simultaneously move each of them forward.
            if(l1)
            {
                sum+= l1 -> val;
                l1 = l1 -> next;
            }

            if(l2)
            {
                sum += l2 -> val;
                l2 = l2 -> next;
            }

            sum+=carry;
            carry = sum/10;

            // We create a new node to store the sum of each digit.
            ListNode* node = new ListNode(sum%10);

            // Then we use the temporary node to point the prev digit to the next digit, and move forward.
            temp -> next= node;
            temp = temp -> next;
        }

        // Since the first node is dummy node, so we consider newList -> next as head.
        return newList -> next;

    }
};