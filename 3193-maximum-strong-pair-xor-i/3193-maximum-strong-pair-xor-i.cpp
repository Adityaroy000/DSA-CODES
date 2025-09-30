class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n = nums.size();
        set<pair<int,int>>st;
        unordered_set<int>el(nums.begin(),nums.end());

        int maxi = *max_element(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            st.insert({nums[i],nums[i]});
            for(int j=nums[i]+1;j<=2*nums[i];j++){
                if(j > maxi) break;
                if(el.count(j)){
                    st.insert({nums[i],j});
                }
            }
        }
        int maxxor = 0;
        for(auto &it: st){
            maxxor = max(maxxor,it.first^it.second);
        }
        return maxxor;
    }
};