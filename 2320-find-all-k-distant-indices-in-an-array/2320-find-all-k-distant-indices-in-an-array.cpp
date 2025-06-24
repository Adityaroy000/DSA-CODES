class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int>idx;
        set<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i] == key){
                idx.push_back(i);
                ans.insert(i);
            }
        }

        for(int i = 0;i<idx.size();i++){
            for(int j = 0;j<n;j++){
                if(idx[i] != j){
                    int diff = abs(idx[i]-j);
                    if(diff<=k){
                        ans.insert(j);
                    }
                }
            }
        }
        vector<int>temp;
        for(auto it:ans){
            temp.push_back(it);
        }
        return temp;
    }
};