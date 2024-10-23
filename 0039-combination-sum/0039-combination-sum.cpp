class Solution {
public:
    void find(vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>>& ans, int index){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target<0) return;
        for(int i = index;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            find(candidates,target-candidates[i],temp,ans,i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        find(candidates,target,temp,ans,0);
        return ans;
    }
};