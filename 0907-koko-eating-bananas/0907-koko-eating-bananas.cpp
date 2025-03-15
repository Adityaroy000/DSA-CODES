class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = *max_element(piles.begin(),piles.end());
        int low = 1,high = maxi;
        while(low<=high){
            int mid = low+(high-low)/2;
            long long cnt = 0;
            for(int i = 0;i<n;i++){
                cnt += (piles[i]+mid-1)/mid;
            }
            
            if(cnt<=h){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;

    }
};