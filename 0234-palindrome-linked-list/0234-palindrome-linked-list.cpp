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
    ListNode* reverseLinkedList(ListNode* head) {
    // Check if the list is empty
    // or has only one node
    if (head == NULL || head->next == NULL) {
        
        // No change is needed;
        // return the current head
        return head; 
    }

    // Recursive step: Reverse the remaining 
    // part of the list and get the new head
    ListNode* newHead = reverseLinkedList(head->next);

    // Store the next node in 'front'
    // to reverse the link
    ListNode* front = head->next;

    // Update the 'next' pointer of 'front' to
    // point to the current head, effectively
    // reversing the link direction
    front->next = head;

    // Set the 'next' pointer of the
    // current head to 'null' to
    // break the original link
    head->next = NULL;

    // Return the new head obtained
    // from the recursion
    return newHead;
}
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next==nullptr){
            return true;
        }
        ListNode *slow = head, *fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *newhead= reverseLinkedList(slow);
        ListNode *first = head, *second = newhead;
        while(second!=nullptr){
            if(first->val!=second->val){
                reverseLinkedList(newhead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLinkedList(newhead);
        return true;

    }
};