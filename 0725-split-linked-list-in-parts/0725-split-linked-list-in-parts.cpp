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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k);
        ListNode *temp = head;
        int cnt = 0;
        while(temp!=nullptr){
            cnt +=1;
            temp = temp->next;
        }
        int size= cnt/k;
        int rem = cnt%k;
        temp = head;
        ListNode *prev = temp;
        for(int i=0;i<k;i++){
            ListNode *newpart = temp;
            int currentsize = size;
            if(rem>0){
                rem--;
                currentsize++;
            }
            int j=0;
            while(j<currentsize){
                prev = temp;
                if(temp!=nullptr){
                    temp = temp->next;
                }
                j++;
            }
            if(prev!=nullptr){
                prev->next = nullptr;
            }
            res[i] = newpart;
        }
        return res;
    }
};