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
    class Compare{
        public:
        bool operator()(ListNode *a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*>temp;
        for(int i = 0; i<lists.size(); i++){
            if(lists[i] != nullptr){
                temp.push_back(lists[i]);
            }
        }
        priority_queue<ListNode*,vector<ListNode*> , Compare>p(temp.begin(),temp.end());
        ListNode* root = new ListNode(0);
        ListNode* tail = root;
        ListNode* t;
        while(!p.empty()){
            t = p.top();
            p.pop();
            tail->next = t;
            tail = tail->next;
            if(t->next){
                p.push(t->next);
            }
        }
        return root->next;
    }
};