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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;

        ListNode* curr = head;
        ListNode* lessHead = new ListNode(-1);
        ListNode* lesstemp = lessHead;

        ListNode* grtHead = new ListNode(-1);
        ListNode* grttemp = grtHead;

        while(curr){
            if(curr->val < x){
                lesstemp->next = curr;
                lesstemp = lesstemp->next;
            }else{
                grttemp->next = curr;
                grttemp = grttemp->next;
            }
            curr = curr->next;
        }
        grttemp->next = NULL;
        lesstemp->next = grtHead->next;
        return lessHead->next;
    }
};