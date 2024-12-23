struct Node{
    Node* link[2];
    bool contains(int bit){
        return (link[bit]!=NULL);
    }
    void put(int bit ,Node* node){
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
                if(!node->contains(bit)){
                    node->put(bit,new Node());
                }
                node = node->link[bit];
            }
        }
    public: 
        int getmax(int num){
            Node* node = root;
            int maxsum = 0;
            for(int i = 31; i>=0; i--){
                int bit = (num>>i)&1;
                if(node->contains(1-bit)){
                    maxsum = maxsum | (1<<i);
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int s = queries.size();
        vector<int>ans(s,0);
        vector<pair<int,pair<int,int>>>offq;
        for(int i = 0; i<s; i++){
            offq.push_back({queries[i][1], {queries[i][0], i}});
        }
        sort(offq.begin(),offq.end());
        int idx = 0;
        for(int i=0; i<s; i++){
            int mi = offq[i].first;
            int xi = offq[i].second.first;
            int qidx = offq[i].second.second;
            while(idx<n && nums[idx]<=mi){
                trie.insert(nums[idx]);
                idx++;
            }
            if(idx == 0) ans[qidx] = -1;
            else ans[qidx] = trie.getmax(xi);
        }
        return ans;
    }
};