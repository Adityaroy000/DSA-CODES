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
    int len(ListNode* head){
        if(!head) return 0;
        ListNode* curr = head;
        int cnt = 0;
        while(curr){
            cnt++;
            curr = curr->next;
        }
        return cnt;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        stack<ListNode*>st;
        ListNode* curr = head;

        int l = len(head);
        int mid = (l+1)/2;
        ListNode* temp = head;
        while(mid != 1){
            mid--;
            temp = temp->next;
        }
        ListNode* last = temp;
        temp = temp->next;
        last->next = NULL;
        while(temp){
            st.push(temp);
            temp = temp->next;
        }
        ListNode* next = curr;
        while(!st.empty() && curr){
            next = curr->next;
            curr->next = st.top();
            st.pop();
            curr = curr->next;
            curr->next = next;
            curr = next;
        }
    }
};