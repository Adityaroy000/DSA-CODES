class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long noofflower = (long long)m*k;
        if(n<noofflower) return -1;
        int mini = *min_element(bloomDay.begin(),bloomDay.end());
        int maxi = *max_element(bloomDay.begin(),bloomDay.end());
        int low = mini;
        int high = maxi;
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            int cnt = 0,no=0;
            for(int i = 0; i<n; i++){
                if(bloomDay[i]<=mid){
                    cnt++;
                    if(cnt == k){
                        no++;
                        cnt = 0;
                    }
                }
                else cnt = 0;
                if(no>=m) break;
            }
            if(no>=m){
                ans = mid;
                high = mid-1;  
            } 
            else low = mid+1;
        }
        return ans;
    }
};