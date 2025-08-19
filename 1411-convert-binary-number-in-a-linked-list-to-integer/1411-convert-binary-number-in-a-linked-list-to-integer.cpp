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
    int getDecimalValue(ListNode* head) {
        string temp = "";
        ListNode* curr = head;
        while(curr){
            temp+=(to_string(curr->val));
            curr = curr->next;
        }
        int ans = stoi(temp,nullptr,2);
        return ans;
    }
};