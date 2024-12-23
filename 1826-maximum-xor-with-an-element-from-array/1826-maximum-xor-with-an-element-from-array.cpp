// struct Node{
//     Node* link[2];
//     bool contains(int bit){
//         return (link[bit]!=NULL);
//     }
//     void put(int bit ,Node* node){
//         link[bit] = node;
//     }
// };
// class Trie{
//     private: Node* root;
//     public: 
//         Trie(){
//             root = new Node();
//         }
//     public: 
//         void insert(int num){
//             Node* node = root;
//             for(int i = 31; i>=0; i--){
//                 int bit = (num>>i)&1;
//                 if(!node->contains(bit)){
//                     node->put(bit,new Node());
//                 }
//                 node = node->link[bit];
//             }
//         }
//     public: 
//         int getmax(int num){
//             Node* node = root;
//             int maxsum = 0;
//             for(int i = 31; i>=0; i--){
//                 int bit = (num>>i)&1;
//                 if(node->contains(1-bit)){
//                     maxsum = maxsum | (1<<i);
//                     node = node->link[1-bit];
//                 }
//                 else{
//                     node = node->link[bit];
//                 }
//             }
//             return maxsum;
//         }
// };
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        //Trie trie;
        int n = nums.size();
        int s = queries.size();
        // for(auto &it : nums){
        //     trie.insert(it);
        // }
        vector<int>ans;
        for(int i = 0; i<s; i++){
            int xi = queries[i][0];
            int mi = queries[i][1];
            int maxi = -1;
            for(int j = 0;j<n; j++){
                if(nums[j]<=mi){
                    maxi = max(maxi,nums[j]^xi);
                }
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};