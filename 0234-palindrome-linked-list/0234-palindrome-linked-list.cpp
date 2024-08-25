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
private:
    ListNode* reverselist(ListNode *head){
        ListNode *prev= nullptr, *curr = head;
        while(curr!=nullptr){
            ListNode *front = curr->next;
            curr->next = prev ;
            prev = curr;
            curr = front;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next == nullptr){
            return true;
        }
        ListNode *slow = head, *fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *secondhalf = reverselist(slow);
        ListNode *firsthalf = head;

        ListNode* copy = secondhalf;
        while(secondhalf!=nullptr){
            if(firsthalf->val != secondhalf->val){
                reverselist(copy);
                return false;
            }
            secondhalf = secondhalf->next;
            firsthalf = firsthalf->next;
        }
        reverselist(copy);
        return true;

        
    }
};