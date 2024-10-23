class Solution {
public:
    void Find(vector<int>& candidates, int target,vector<int>& temp,vector<vector<int>>& ans,int index){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target<0) return;
        for(int i = index; i<candidates.size();i++){
            if(i>index&&candidates[i]==candidates[i-1]) 
                continue;
            temp.push_back(candidates[i]);
            Find(candidates,target-candidates[i],temp,ans,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        Find(candidates,target,temp,ans,0);
        return ans;
    }
};