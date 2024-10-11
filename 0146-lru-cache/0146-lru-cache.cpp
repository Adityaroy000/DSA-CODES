class LRUCache {
public:
    class node{
        public:
        int key,val;
        node* next;
        node* prev;
        node(int key1,int val1){
            key = key1;
            val = val1;
        }
    };
    int cap;
    unordered_map<int,node*>mpp;
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void deletenode(node* delnode){
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    void insertnode(node* newnode){
        node* temp = head->next;
        newnode->next = temp;
        temp->prev = newnode;
        head->next = newnode;
        newnode->prev = head;
    }
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            node* currnode = mpp[key];
            int ans = currnode->val;
            deletenode(currnode);
            insertnode(currnode);
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            node* existingnode = mpp[key];
            existingnode->val = value;
            deletenode(existingnode);
            insertnode(existingnode);
        }
        else {
            if(mpp.size()==cap){
                node* temp = tail->prev;
                mpp.erase(temp->key);
                deletenode(temp);
            }
            node* newnode = new node(key,value);
            mpp[key]=newnode;
            insertnode(newnode);
        }
        

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */