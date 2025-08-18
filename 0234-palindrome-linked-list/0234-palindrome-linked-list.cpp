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
        vector<int>aage;
        ListNode* curr = head;
        while(curr->next){
            aage.push_back(curr->val);
            curr = curr->next;
        }
        aage.push_back(curr->val);

        int start = 0,end = aage.size()-1;
        while(start<=end){
            if(aage[start] == aage[end]){
                start++;
                end--;
            }else return false;
        }
        return true;
    }
};