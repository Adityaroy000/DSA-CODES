class Solution {
public:
    void find(vector<int>& nums,int n,vector<int>& temp,vector<vector<int>>& ans,int i,set<vector<int>>& st){
        if(i==n){
            if(st.find(temp)!=st.end()) return;
            ans.push_back(temp);
            st.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        find(nums,n,temp,ans,i+1,st);
        temp.pop_back();
        find(nums,n,temp,ans,i+1,st);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>temp;
        set<vector<int>>st;
        vector<vector<int>>ans;
        find(nums,n,temp,ans,0,st);
        return ans;
    }
};