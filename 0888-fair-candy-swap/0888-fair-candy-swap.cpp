class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int m = aliceSizes.size();
        int n = bobSizes.size();
        vector<int>ans;
        int sumA = accumulate(aliceSizes.begin(),aliceSizes.end(),0);
        int sumB = accumulate(bobSizes.begin(),bobSizes.end(),0);

        sort(bobSizes.begin(),bobSizes.end());

        int req = (sumB-sumA)/2;
        // y = x+(sumB-sumA)/2

        for(int i=0;i<m;i++){
            int x = aliceSizes[i];
            int y = x+req;
            bool flag = false;
            int low = 0, high = n-1;
            while(low<=high){
                int mid = (high+low)/2;
                if(bobSizes[mid] == y) {
                    ans.push_back(x);
                    ans.push_back(y);
                    flag = true;
                    break;
                }else if(bobSizes[mid]>y) high = mid-1;
                else low = mid+1;
            } 
            if(flag) break;
        }
        return ans;

    }
};