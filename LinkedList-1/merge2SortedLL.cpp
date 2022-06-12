// Here we use merge sort to sort the 2 sorted LL.
// We do not use any extra space here so Space Complexity is O(1);

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        // We always want list1 pointer to be smaller than list2 pointer.
        if(list1 -> val > list2 -> val)
            swap(list1,list2);

        ListNode* ans = list1;

        while(list1 && list2)
        {
            // We create a temporary node to point the next node when swap takes place.
            ListNode* temp = list1;
            while(list1 && list1 -> val <= list2 -> val)
            {
                temp = list1;
                list1 = list1 -> next;
            }

            temp -> next = list2;
            // Since we want list1 pointer to be smaller than list2 pointer, we swap the pointers.
            swap(list1,list2);
        }

        return ans;
    }
};