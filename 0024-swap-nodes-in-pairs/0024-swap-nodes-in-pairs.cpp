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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* curr = head;
        ListNode* next = head;
        ListNode* prev = NULL;

        head = curr->next;

        while(curr && curr->next){
            next = curr->next;
            if(next){
                curr->next = next->next;
                next->next = curr;
            } 
            if(prev) prev->next = next;
            prev = curr;
            
            curr = curr->next;
            next = curr;
        }

        return head;

    }
};