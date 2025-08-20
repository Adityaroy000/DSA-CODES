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
        vector<ListNode*>temp;
        ListNode* curr = head;
        while(curr){
            temp.push_back(curr);
            curr = curr->next;
        }
        int size = temp.size();
        int tar = size - n;
        
        if(tar == 0){
            ListNode* newHead = head->next;
            delete head; 
            return newHead;
        }
        ListNode* prev = temp[tar - 1];
        ListNode* delNode = prev->next;
        prev->next = delNode->next;
        delete delNode;
        
        return head;
    }
};