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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*>st;
        ListNode* ta = headA;
        ListNode* tb = headB;

        while(ta && tb){
            if(st.find(ta)!= st.end()){
                return ta;
            }else if(st.find(tb)!=st.end()){
                return tb;
            }else if(ta == tb) return ta;
            
            st.insert(ta);
            st.insert(tb);

            ta = ta->next;
            tb = tb->next;
        }
        while(ta){
            if(st.find(ta)!= st.end()){
                return ta;
            }
            st.insert(ta);
            ta = ta->next;
        }
        while(tb){
            if(st.find(tb)!= st.end()){
                return tb;
            }
            st.insert(tb);
            tb = tb->next;
        }
        return NULL;
    }
};