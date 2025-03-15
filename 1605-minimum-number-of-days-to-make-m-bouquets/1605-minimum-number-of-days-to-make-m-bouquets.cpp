class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long) m*k > n) return -1;
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int mindays= -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            int cnt = 0,nob =  0;
            for(int i = 0;i<n;i++){
                if(bloomDay[i]<=mid) {
                    cnt++;
                    if(cnt == k) {
                        nob++;
                        cnt = 0;
                    }
                }
                else cnt = 0;
            }
            if(nob >= m){
                mindays = mid;
                high = mid-1;
            }else low = mid+1;
        }
        if(mindays == -1) return -1;
        else return mindays;
    }
};