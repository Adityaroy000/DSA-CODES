class Solution {
public:
    void find(vector<int>& nums,int n,vector<int>& temp,vector<vector<int>>& ans,int i){
        ans.push_back(temp);
        
        for(int j = i; j<n; j++){
            if(j>i&&nums[j]==nums[j-1]) continue;
            temp.push_back(nums[j]);
            find(nums,n,temp,ans,j+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>temp;
        vector<vector<int>>ans;
        find(nums,n,temp,ans,0);
        return ans;
    }
};