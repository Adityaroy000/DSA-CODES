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
    int length(ListNode* head){
        ListNode* temp = head;
        int cnt = 0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) return head;
        ListNode* temp = head;
        int n = length(head);
        k = k%n;
        if(k==0) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i = 0; i<k; i++){
            fast = fast->next;
        }
        while(fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* newhead = slow->next;
        slow->next = NULL;
        fast->next = head;
        return newhead;
    }
};