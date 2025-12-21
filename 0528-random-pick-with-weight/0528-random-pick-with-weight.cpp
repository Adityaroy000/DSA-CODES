class Solution {
public:
    vector<int>pre;
    int high = 0;
    Solution(vector<int>& w) {
        int n = w.size();
        int sum = 0;
        high = n-1;
        for(int i=0;i<n;i++){
            sum += w[i];
            pre.push_back(sum);
        }
    }
    
    int pickIndex() {
        int ans= -1;
        int r = rand()%pre.back() +1;
        int l=0,h = high;
        while(l<=h){
            int mid = (l+h)/2;
            if(pre[mid]>=r) {
                ans = mid;
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */