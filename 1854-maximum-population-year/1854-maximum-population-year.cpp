class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n = logs.size();
        vector<int>ans(2051);
        for(int i=1950;i<=2050;i++){
            for(int j=0;j<n;j++){
                if(logs[j][0]<=i && logs[j][1]>i) ans[i]++;
            }
        }
        int maxi = 0;
        int idx = -1;
        for(int i=1950;i<ans.size();i++){
            if(maxi<ans[i]){
                maxi = ans[i];
                idx = i;
            }
        }
        return idx;
    }
};