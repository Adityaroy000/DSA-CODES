/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int length(ListNode* head){
        ListNode* temp = head;
        int cnt =0;
        while(temp!=NULL){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    int getdiff(ListNode* head1,ListNode* head2){
        int a = length(head1);
        int b = length(head2);
        int diff;
        if(a>b){
            diff = a-b;
        }else{
            diff = b-a;
        }
        return diff;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB == NULL) return NULL;
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        int l1 = length(headA);
        int l2 = length(headB);
        int n = getdiff(headA,headB);
        if(l1>l2){
            ListNode*t = headA;
            for(int i = 1;i<=n;i++){
                t = t->next;
            }
            headA = t;
        }else{
            ListNode* t = headB;
            for(int i=1;i<=n;i++){
                t = t->next;
            }
            headB = t;
        }
        while(headA!=NULL&&headB!= NULL){
            if(headA==headB){
                return headA;
            }else{
                headA = headA->next;
                headB = headB->next;
            }
        }
        headA = t1;
        headB = t2;
        return NULL;
    }
};