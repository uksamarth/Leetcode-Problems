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
    
    int pairSum(ListNode* a) {
        ListNode* b=a;
        vector<int>v;

        while(b)
        v.push_back(b->val),
        b=b->next;

        int i=0,j=v.size()-1,maxi=-1;

        while(i<j)
            maxi=max(v[i++]+v[j--],maxi);
        
        return maxi;

    }
};