class Solution {
public:
    vector<vector<int>> seq(vector<int>& nums,vector<int>& temp,int i){
        vector<vector<int>>req;
        if(i==nums.size()){
            req.push_back(temp);
            return req;
        } 
        temp.push_back(nums[i]);
        vector<vector<int>>inc = seq(nums,temp,i+1);
        temp.pop_back();
        vector<vector<int>>exc = seq(nums,temp,i+1);
        req.insert(req.end(),inc.begin(),inc.end());
        req.insert(req.end(),exc.begin(),exc.end());
        return req;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        return seq(nums,temp,0); 
    }
};