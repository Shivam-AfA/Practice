// This question can be solved in two ways.

// 1st solution
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int count = 0;

        // Here we find the find the size of the list first by traversing through the whole list.
        while(temp)
        {
            count++;
            temp = temp -> next;
        }
        int middle = 0;

        // Then we find the middle element
        if(count%2==0)
        {
            middle = count/2;
        }
        else
        {
            middle = (count/2) ;
        }

        int i=0;
        temp = head;

        // Then we find the iddle node and return it
        for(i=0; i< middle ; i++)
        {
            temp = temp->next;
        }

        return temp;
    }
};


// 2nd solution
Node *findMiddle(Node *head) {
    // Here we use two pointers, fast and slow. We move the slow pointer by 1 step and fast pointer by
    // 2 steps.

    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    return slow;
}