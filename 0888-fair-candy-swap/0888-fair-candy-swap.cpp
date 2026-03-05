class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int m = aliceSizes.size();
        int n = bobSizes.size();

        vector<int>ans;
        int sumA = accumulate(aliceSizes.begin(),aliceSizes.end(),0);
        int sumB = accumulate(bobSizes.begin(),bobSizes.end(),0);

        unordered_set<int>bob;
        for(int i=0;i<n;i++){
            bob.insert(bobSizes[i]);
        }
        int req = (sumB-sumA)/2;
        // y = x+(sumB-sumA)/2

        for(int i=0;i<m;i++){
            int x = aliceSizes[i];
            int y = x+req;

            if(bob.find(y)!=bob.end()){
                ans.push_back(x);
                ans.push_back(y);
                break;
            }
        }
        return ans;

    }
};