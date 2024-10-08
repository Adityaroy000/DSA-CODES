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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast = head;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev=NULL;
        ListNode* curr=slow;
        ListNode* next = slow;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr=next;
        }
        fast = prev;
        ListNode* temp = head;
        while(temp!=slow){
            if(temp->val==fast->val){
                temp=temp->next;
                fast=fast->next;
            }else{
                return false;
            }
        }
        return true;
    }
};