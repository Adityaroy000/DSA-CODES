class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(),intervals.end());

        int cnt = 0;
        int i=0;
        while(i<n){
            int end = intervals[i][1];
            int j = i+1;
            while(j<n && end>intervals[j][0]){
                cnt++;
                end = min(end,intervals[j][1]);
                j++;
            }
            i = j;
        }
        return cnt;
    }
};