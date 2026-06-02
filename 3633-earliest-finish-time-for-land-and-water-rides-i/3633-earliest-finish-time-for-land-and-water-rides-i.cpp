class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        int ans = INT_MAX;
        
        for(int i=0;i<n;i++){
            int time = landStartTime[i]+landDuration[i];
            for(int j=0;j<m;j++){
                int temp = time;
                if(waterStartTime[j] > temp){
                    temp += (waterStartTime[j]-temp)+waterDuration[j];
                }else{
                    temp += waterDuration[j];
                }
                ans = min(ans,temp);
            }
        }
        for(int i=0;i<m;i++){
            int time = waterStartTime[i]+waterDuration[i];
            for(int j=0;j<n;j++){
                int temp = time;
                if(landStartTime[j] > temp){
                    temp += (landStartTime[j]-temp)+landDuration[j];
                }else{
                    temp += landDuration[j];
                }
                
                ans = min(ans,temp);
            }
        }
        return ans;
    }
};