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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;

        vector<ListNode*>temp;
        ListNode* curr = head;
        while(curr){
            temp.push_back(curr);
            curr = curr->next;
        }

        int n = temp.size();
        if(k>=n) k = k%n;

        if(k == 0) return head;

        ListNode* start = head;

        ListNode* prev = temp[n-k-1];
        curr = temp[n-k];
        prev->next = NULL;

        head = curr;

        for(int i=(n-k);i<n;i++){
            curr = temp[i];
        }
        curr->next = start;

        return head;
    }
};