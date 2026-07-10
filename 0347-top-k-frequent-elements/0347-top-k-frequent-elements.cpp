class Solution {
public:
    typedef pair<int,int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        unordered_map<int,int>mpp;

        for(int x : nums) mpp[x]++;

        priority_queue<p,vector<p>>pq;

        for(auto it : mpp){
            pq.push({it.second,it.first});
        }

        for(int i=1;i<=k;i++){
            auto [cnt, el] = pq.top();
            pq.pop();
            ans.push_back(el);
        }

        return ans;
    }
};