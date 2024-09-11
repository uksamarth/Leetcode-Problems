class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to act as the starting point of the merged list
        ListNode dummy;
        ListNode* tail = &dummy;

        // While neither list is exhausted
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // If one of the lists is not exhausted, append it to the merged list
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        // The merged list is pointed to by dummy.next
        return dummy.next;
    }
};
