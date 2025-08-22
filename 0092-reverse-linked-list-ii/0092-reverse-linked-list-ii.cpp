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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;
        for(int i=0;i<left-1;i++){
            curr = curr->next;
        }

        ListNode* tail = curr->next;
        for(int i=0;i<right-left;i++){
            ListNode* node_to_move = tail->next;
            tail->next = node_to_move->next;

            node_to_move->next = curr->next;
            curr->next = node_to_move;
        }
        return dummy->next;
    }
};