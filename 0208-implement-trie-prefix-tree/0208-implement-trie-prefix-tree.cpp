struct Node{
    Node* links[26];
    bool flag = false;
    bool contains(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }
    Node* moveNode(char ch){
        return links[ch-'a'];
    }
};
class Trie {
    private: Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i<word.length(); i++){
            if(!node->contains(word[i])){
                node->put(word[i],new Node());
            }
            node = node->moveNode(word[i]);
        }
        node->flag = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i = 0 ; i<word.length(); i++){
            if(!node->contains(word[i])){
                return false;
            }
            node = node->moveNode(word[i]);
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0;i<prefix.length(); i++){
            if(!node->contains(prefix[i])){
                return false;
            }
            node = node->moveNode(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */