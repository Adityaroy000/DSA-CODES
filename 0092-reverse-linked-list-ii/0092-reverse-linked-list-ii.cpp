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
        
        ListNode* curr = head;
        ListNode* start = NULL;
        ListNode* end = NULL;
        ListNode* prev;
        ListNode* start_ka_prev;

        int l=1,r=1;
        while(curr){
            if(l == (left-1)) start_ka_prev = curr;
            if(l==left){
                start = curr;
            }
            if(r == right){
                end = curr;
                prev = end->next;
            }
            l++;
            r++;
            if(start && end) break;
            curr = curr->next;
        }

        curr = start;
        ListNode* next = curr;
        if(start_ka_prev) start_ka_prev->next = end;
        while(curr != end){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        curr->next = prev;
        prev = curr;
        if(left == 1 && right != 1) return prev;
        
        return head;
    }
};