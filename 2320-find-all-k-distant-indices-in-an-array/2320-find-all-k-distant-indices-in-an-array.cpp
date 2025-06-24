class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int>idx;
        for(int i=0;i<n;i++){
            if(nums[i] == key){
                idx.push_back(i);
            }
        }
        
        vector<int>vis(n,0);

        for(int i:idx){
            int left = max(0,i-k);
            int right = min(n-1,i+k);

            for(int j = left;j<=right; j++){
                vis[j] = 1;
            }
        }
        
        vector<int>temp;
        for(int i = 0;i<n;i++){
            if(vis[i])
                temp.push_back(i);
        }
        return temp;
    }
};