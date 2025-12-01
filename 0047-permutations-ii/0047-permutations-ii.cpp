class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>>st;
        sort(nums.begin(),nums.end());
        st.insert(nums);

        vector<vector<int>>ans;
        while(true){
            int idx = -1;
            for(int i=n-2;i>=0;i--){
                if(nums[i]<nums[i+1]){
                    idx = i;
                    break;
                }
            }
            if(idx == -1) break;

            for(int i=n-1;i>idx;i--){
                if(nums[i]>nums[idx]){
                    swap(nums[i],nums[idx]);
                    break;
                }
            }

            reverse(nums.begin()+idx+1,nums.end());
            st.insert(nums);
        }

        for(auto &it:st){
            ans.push_back(it);
        }
        return ans;
    }
};