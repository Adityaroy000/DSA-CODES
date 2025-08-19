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
        ListNode* start1 = l1;
        ListNode* start2 = l2;

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        int carry = 0;
        while(start1 || start2 || carry){
            int one = start1?start1->val:0;
            int two = start2?start2->val:0;

            int sum = one + two + carry;
            carry = sum/10;
            int ld = sum%10;

            ListNode* newnode = new ListNode(ld);
            temp->next = newnode;
            temp = newnode;

            if(start1) start1 = start1->next;
            if(start2) start2 = start2->next;
        }
        
        return dummy->next;
    }
};