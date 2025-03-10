class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lsum = 0,rsum = 0;
        int maxsum = 0,right = n-1;

        for(int i = 0; i<=k-1; i++){
            lsum += cardPoints[i];
        }

        maxsum = lsum;

        for(int i = k-1; i>=0; i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[right];
            right--;
            maxsum = max(lsum+rsum,maxsum);
        }

        return maxsum;
    }
};