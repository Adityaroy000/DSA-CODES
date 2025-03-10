class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lsum = 0,rsum = 0;
        int maxsum = 0,cnt  = 0,left = 0,right  = n-1,kd = k-1;
        while(kd>=0){
            if(cnt != k){
                lsum += cardPoints[left];
                left++;
                cnt++;
            }
            else if(cnt == k){
                maxsum = max(lsum+rsum,maxsum);
                lsum -= cardPoints[kd];
                kd--;
                rsum += cardPoints[right];
                right--;
            } 
        }
        maxsum = max(lsum+rsum,maxsum);

        return maxsum;
    }
};