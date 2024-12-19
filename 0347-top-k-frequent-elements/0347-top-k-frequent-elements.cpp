class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        for(int i = 0; i<n; i++){
            if(mpp.find(nums[i])!=mpp.end()){
                mpp[nums[i]]++;
            }
            else{
                mpp[nums[i]] = 1;
            }
        }
        vector<pair<int,int>>temp(mpp.begin(),mpp.end());
        for(int i = 0; i<temp.size(); i++){
            for(int j = i+1; j<temp.size(); j++){
                if(temp[i].second<temp[j].second){
                    auto it = temp[i];
                    temp[i] = temp[j];
                    temp[j] = it;
                }
            }
        }
        vector<int>ans;
        for(int i = 0;i<k; i++){
            ans.push_back(temp[i].first);
        }
        return ans;
    }
};