class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> to_remove(nums.begin(), nums.end());

        // Step 1: Create a dummy node before the head
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        // Step 2: Use a pointer to track the current node
        ListNode* current = dummy;

        while (current->next != nullptr) {
            if (to_remove.count(current->next->val)) {
                // Remove the node by skipping it
                current->next = current->next->next;
            } else {
                // Move to the next node
                current = current->next;
            }
        }

        // Step 3: Return the modified list (without the dummy)
        return dummy->next;
    }
};
