class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        long long sum = 0;
        int maxpile = INT_MIN;
        for(int i = 0; i<n; i++){
            maxpile = max(maxpile,piles[i]);
            sum += piles[i];
        }
        int k = max(1,(int)(sum/h));
        for(int i = k; i<=maxpile;i++){
            int cnt = 0;
            for(int j = 0; j<n; j++){
                if(piles[j]%i==0) {
                    cnt += piles[j]/i;
                }
                else{
                    cnt += (piles[j]/i)+1;
                }
            }
            if(cnt <= h) return i;
        }
        return 0;
    }
};