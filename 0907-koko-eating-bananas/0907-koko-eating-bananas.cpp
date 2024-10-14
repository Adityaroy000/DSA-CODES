class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        long long maxi = *max_element(piles.begin(),piles.end());
        int low = 1;
        long long high = maxi;
        while(low<=high){
            int mid = low+(high-low)/2;
            long long cnt = 0;
            for(int i = 0; i<n; i++){
                if(piles[i]%mid==0) cnt += (piles[i]/mid);
                else cnt += (piles[i]/mid)+1;
            }
            if(cnt<=h) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};