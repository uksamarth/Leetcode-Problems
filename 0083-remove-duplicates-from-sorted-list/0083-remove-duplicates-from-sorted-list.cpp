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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head){
            return nullptr;
        }
        ListNode* curr = head;
        ListNode* temp = head->next;
        int last = head->val;
        while(temp!=nullptr){
            if(temp->val==last){
                if(temp->next==nullptr){
                    curr->next = nullptr;
                    delete temp;
                    break;
                }
                temp = temp->next;
                curr->next = temp;
            }
            else{
                curr = temp;
                last = curr->val;
                temp = temp->next;
            }
        }
        return head;
    }
};