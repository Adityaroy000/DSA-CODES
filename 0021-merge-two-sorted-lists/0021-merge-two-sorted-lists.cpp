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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        ListNode* newl = new ListNode(-1);
        ListNode* temp = newl;

        while(temp1 && temp2){
            if(temp1->val < temp2->val){
                ListNode* newnode = new ListNode(temp1->val);
                temp->next = newnode;
                temp1 = temp1->next;
            }else{
                ListNode* newnode = new ListNode(temp2->val);
                temp->next = newnode;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        while(temp1){
            ListNode* newnode = new ListNode(temp1->val);
            temp->next = newnode;
            temp1 = temp1->next;
            temp = temp->next;
        }
        while(temp2){
            ListNode* newnode = new ListNode(temp2->val);
            temp->next = newnode;
            temp2 = temp2->next;
            temp = temp->next;
        }
        return newl->next;
    }
};