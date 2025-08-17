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
        ListNode* prev = head;
        ListNode* next = head;

        while(next){
            if(next->next && next->next->val == prev->val){
                next = next->next;
                prev->next = next->next;
                next = prev;
            }else{
                prev = prev->next;
                next = next->next;
            }
        }
        return head;
    }
};