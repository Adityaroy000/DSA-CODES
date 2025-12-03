class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end());

        int i=0;
        int cnt = 0;
        while(i<n){
            int end = points[i][1];
            int j = i+1;
            while(j<n && end >= points[j][0]){
                if(end > points[j][1]){
                    end = points[j][1];
                }
                j++;
            }
            i = j;
            cnt ++;
        }
        return cnt;
    }
};