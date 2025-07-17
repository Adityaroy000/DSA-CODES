class Solution {
public:
    set<vector<int>>st;
    void solve(vector<int>& arr,vector<int> nums,vector<vector<int>>& ans){
        if(nums.size()==0){
            if(st.find(arr)==st.end()){
                ans.push_back(arr);
                st.insert(arr);
            }
            return;
        }

        vector<int>a1 = arr;
        vector<int>a2 = arr;
        a2.push_back(nums[0]);

        nums.erase(nums.begin()+0);

        solve(a1,nums,ans);
        solve(a2,nums,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>arr;
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        solve(arr,nums,ans);
        return ans;
    }
};