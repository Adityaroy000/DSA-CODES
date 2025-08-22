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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;

        ListNode* curr = head;
        ListNode* diff;
        vector<ListNode*>vec;
        vector<ListNode*>bara;

        bool flag = false;
        while(curr){
            if(curr->val == x && !flag ){
                diff = curr;
                bara.push_back(curr);
                flag = true;
            } 
            else if(curr->val < x){
                vec.push_back(curr);
            }else{
                bara.push_back(curr);
            }
            curr = curr->next;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        for(int i=0;i<vec.size();i++){
            ListNode* newnode = new ListNode(vec[i]->val);
            temp->next = newnode;
            temp = newnode;
        }
        for(int i=0;i<bara.size();i++){
            ListNode* newnode = new ListNode(bara[i]->val);
            temp->next = newnode;
            temp = newnode;
        }
        return dummy->next;
    }
};