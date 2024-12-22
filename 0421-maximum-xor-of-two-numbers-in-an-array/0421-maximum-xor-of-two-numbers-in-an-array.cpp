struct Node{
    Node* link[2];
    bool contain(int bit){
        return (link[bit]!=NULL);
    }
    void put(int bit,Node* node){
        link[bit] = node;
    }
};
class Trie{
    private: Node* root;
    public: 
        Trie(){
            root = new Node();
        }
    public:
        void insert(int num){
            Node* node = root;
            for(int i = 31; i>=0; i--){
                int bit = (num>>i)&1;
                if(!node->contain(bit)){
                    node->put(bit,new Node());
                }
                node = node->link[bit];
            } 
        }
    public: 
        int getMax(int num){
            Node* node = root;
            int maxsum = 0;
            for(int i = 31; i>=0; i--){
                int bit = (num>>i)&1;
                if(node->contain(1-bit)){
                    maxsum = maxsum|(1<<i);
                    node = node->link[1-bit];
                }
                else{
                    node = node->link[bit];
                }
            }
            return maxsum;
        }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        Trie trie;
        for(auto &it : nums){
            trie.insert(it);
        }
        int maxi = 0;
        for(auto &it : nums){
            maxi = max(maxi,trie.getMax(it));
        }
        return maxi;
    }
};