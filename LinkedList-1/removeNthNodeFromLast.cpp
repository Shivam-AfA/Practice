// We have 2 solutions for this question
// Here we remove the nth node from the end of the LL by first iterating through the LL and finding
// the number of elements in the LL.

// 1st solution

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* curr = head;
        int count = 0;
        while(temp)
        {
            count++;
            temp = temp->next;
        }

        // Special condition
        if(count == n)
            return curr -> next;

        // Taking the curr pointer to 1 node behind the pointer to be removed.
        for(int i=0; i< count - (n+1); i++)
        {
            curr = curr -> next;
        }

        if(curr -> next)
        curr -> next = curr ->next -> next;
        return head;
    }
};


// 2nd Solution

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* start = new ListNode();
    start -> next = head;
    ListNode* slow = start;
    ListNode* fast = start;

// Here we first move the fast pointer by n places. So the remaining places is size - n;
    for(int i=0; i<n; i++)
        fast = fast -> next;

// So while fast pointer reaches the end, the slow pointer moves simulaneously. This concept is correct
// since we had to move the decisive pointer(here it is slow pointer) by size - n places. And the fast
// pointer had size - n places remaining to move to reach till the end.
    while(fast -> next)
    {
        slow = slow -> next;
        fast = fast -> next;
    }

    slow -> next = slow -> next -> next;

// Here we have to return start -> next, not head;
    return start -> next;
}
};