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
        if(!head || !head->next) return head;

        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr){
            bool flag = false;
            while(curr->next && curr->val == curr->next->val){
                flag = true;
                curr = curr->next;
            }
            if(!flag){
                prev = curr;
                curr = curr->next;
            }else{
                if(prev) prev->next = curr->next;
                else head = curr->next;
                curr = curr->next;
            }
        }

        return head;
    }
};