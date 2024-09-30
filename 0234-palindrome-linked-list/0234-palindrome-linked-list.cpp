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
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = head;
        vector<int>tmp;
        while(curr!=NULL){
            tmp.push_back(curr->val);
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        vector<int>tmp2;
        while(head!=NULL){
            tmp2.push_back(head->val);
            head = head->next;
        }
        if(tmp == tmp2){
            return true;
        }else{
            return false;
        }
    }
};