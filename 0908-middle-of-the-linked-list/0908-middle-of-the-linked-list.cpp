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
    ListNode* middleNode(ListNode* head) {
        int cnt = length(head);
        int mid;
        if(cnt%2==0){
            mid = ((cnt+1)/2)+1;
        }else{
            mid = ((cnt+1)/2);
        }
        ListNode* temp = head;
        for(int i = 1; i<mid; i++){
            temp = temp->next;
        }
        return temp;
    }
};