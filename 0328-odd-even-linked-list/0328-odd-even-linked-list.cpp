class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;  // If list is empty or has one node
        
        ListNode* odd = head;              // Odd pointer starts at the first node
        ListNode* even = head->next;       // Even pointer starts at the second node
        ListNode* evenHead = even;         // Keep track of the start of the even list
        
        while (even && even->next) {
            odd->next = odd->next->next;   // Link the next odd node
            even->next = even->next->next; // Link the next even node
            odd = odd->next;               // Move odd pointer to the next odd node
            even = even->next;             // Move even pointer to the next even node
        }
        
        odd->next = evenHead;  // Append the even list to the end of the odd list
        return head;
    }
};
