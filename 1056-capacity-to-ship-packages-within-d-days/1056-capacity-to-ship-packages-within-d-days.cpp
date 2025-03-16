class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxc = 0;
        for(int i = 0;i<n; i++){
            maxc += weights[i];
        }
        int high = maxc;
        int low = *max_element(weights.begin(),weights.end());
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            int sum = 0,cnt = 0;
            int i = 0;
            while(i<n){
                if(sum+weights[i] > mid) {
                    cnt++;
                    sum = 0;
                }else {
                    sum+=weights[i];
                    i++;
                }
                if(cnt>days) break;
            }
            
            if(cnt+1 <= days) {
                ans = mid;
                high = mid-1;
            }else low = mid+1;
        }
        return ans;
    }
};