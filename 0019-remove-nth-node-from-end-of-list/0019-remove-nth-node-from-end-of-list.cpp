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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return head;
        
        ListNode* temp = head;
        ListNode* curr = head;
        int cnt =0;
        while(temp!=NULL){
            cnt++;
            temp = temp->next;
        }
        temp=head;
        if((cnt-n)==0) {
            head = head->next;
            return head;
        }
        for(int i = 0; i<cnt-n; i++){
            curr = temp;
            temp = temp->next;
        }
        curr->next = temp->next;
        temp->next = NULL;
        return head;
    }
};