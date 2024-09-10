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
    int gcd(int a,int b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *temp = head;
        ListNode *next = head->next;
        while(temp->next!=nullptr && temp!=nullptr){
            int gcdvalue = gcd(temp->val,next->val);
            ListNode *inserted = new ListNode(gcdvalue);
            inserted->next = next;
            temp->next = inserted;
            temp = next;
            next = next->next;
        }
        return head;

    }
};