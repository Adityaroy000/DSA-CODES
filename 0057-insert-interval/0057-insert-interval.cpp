class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int m = newInterval.size();

        intervals.push_back({newInterval[0],newInterval[1]});

        sort(intervals.begin(),intervals.end());

        vector<vector<int>>ans;
        ans.push_back(intervals[0]);

        for(int i=1;i<intervals.size();i++){
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