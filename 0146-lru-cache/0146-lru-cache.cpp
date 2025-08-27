class LRUCache {
private:
    struct ListNode{
        int key;
        int val;
        ListNode *next;
        ListNode *prev;
        ListNode(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
    };
public:
    unordered_map<int,ListNode*>mpp;
    ListNode* head;
    ListNode* tail;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        head = new ListNode(-1,-1);
        tail = new ListNode(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    void move(ListNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;
        ListNode* p = mpp[key];
        int ans = p->val;

        move(p);
        return ans;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            ListNode* curr = mpp[key];
            curr->val = value;
            move(curr);
            return;
        }

        if(mpp.size()==cap){
            ListNode* del = tail->prev;
            mpp.erase(del->key);
            del->prev->next = tail;
            tail->prev = del->prev;
            delete del;
        }

        ListNode* newnode = new ListNode(key,value);
        mpp[key] = newnode;
        newnode->next = head->next;
        newnode->prev = head;
        
        head->next->prev = newnode;
        head->next = newnode;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */