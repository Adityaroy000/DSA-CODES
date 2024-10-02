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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int carry=0;
        int res;
        while(t1!=NULL || t2!=NULL){
            if(t2==NULL&&t1!=NULL){
                res = t1->val+carry;
            }else if(t1==NULL && t2!=NULL){
                res = t2->val +carry;
            }else{
                res = t1->val + t2->val+carry;
            }
            if(res<10){
                carry = 0;
            }else{
                res = res%10;
                carry = 1;
            }
            curr->next = new ListNode(res);
            curr = curr->next;
            if(t1!=NULL) t1 = t1->next;
            if(t2!=NULL) t2=t2->next;
        }
        if(carry == 1){
            curr->next = new ListNode(1);
            curr= curr->next;
        }
        return dummy->next;
    }
};