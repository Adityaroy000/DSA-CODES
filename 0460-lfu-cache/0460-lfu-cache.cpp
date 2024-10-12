class LFUCache {
public:
    class node{
        public:
        int key,val,freq;
        list<node*>::iterator pos; 
        node* next;
        node* prev;
        node(int key1,int val1){
            key = key1;
            val = val1;
            freq = 1;
        }
    };
    int cap;
    int minfreq;
    unordered_map<int,list<node*>>freqmpp;
    unordered_map<int,node*>keympp;

    void deletenode(node* delnode){
        freqmpp[delnode->freq].erase(delnode->pos);
        if(freqmpp[delnode->freq].empty()){
            freqmpp.erase(delnode->freq);
            if(delnode->freq==minfreq){
                minfreq++;
            }
        }
        keympp.erase(delnode->key);
        delete delnode;
    }
    void insertnode(node* newnode){
        minfreq = 1;
        freqmpp[1].push_back(newnode);
        keympp[newnode->key]=newnode;
        newnode->pos = --freqmpp[1].end();
    }
    LFUCache(int capacity) {
        cap = capacity;
        minfreq=0;
    }
    
    int get(int key) {
        if(keympp.find(key)!=keympp.end()){
            node* existingnode = keympp[key];
            int ans = existingnode->val;
            updatefreq(existingnode);
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cap==0) return;
        if(keympp.find(key)!=keympp.end()){
            node* existingnode = keympp[key];
            existingnode->val = value;
            updatefreq(existingnode);
        }
        else {
            if(keympp.size()==cap){
                node* temp = freqmpp[minfreq].front();
                deletenode(temp);
            }
            node* newnode = new node(key,value);
            insertnode(newnode);
        }
    }
    void updatefreq(node* existingnode){
        int oldfreq = existingnode->freq;
        existingnode->freq++;
        freqmpp[oldfreq].erase(existingnode->pos);
        if(freqmpp[oldfreq].empty()){
            freqmpp.erase(oldfreq);
            if(minfreq==oldfreq){
                minfreq++;
            }
        }
        freqmpp[existingnode->freq].push_back(existingnode);
        existingnode->pos = --freqmpp[existingnode->freq].end();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */