class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int ans = -1;
        int mini = *max_element(weights.begin(),weights.end());
        int maxi = accumulate(weights.begin(),weights.end(),0);
        int low = mini,high = maxi;
        while(low<=high){
            int mid = low+(high-low)/2;
            int cnt = 0,day = 0;
            for(int k = 0;k<n; k++){
                cnt += weights[k];
                if(cnt>mid){
                    day++;
                    cnt = weights[k];
                    if(cnt>mid) break;
                }
            }
            if(cnt <= mid) day++;
            if(day <= days){
                ans = mid;
                high = mid-1;
            }else low = mid+1; 
        }
        return ans;
    }
};