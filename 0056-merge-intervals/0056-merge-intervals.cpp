class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);

        for(int i=1;i<n;i++){
            vector<int>temp = ans.back();
            if(temp[1]>=intervals[i][0]){
                if(temp[1]>=intervals[i][1]){
                    continue;
                }else{
                    ans.pop_back();
                    ans.push_back({temp[0],intervals[i][1]});
                }
            }else{
                ans.push_back({intervals[i][0],intervals[i][1]});
            }
        }
        return ans;
    }
};