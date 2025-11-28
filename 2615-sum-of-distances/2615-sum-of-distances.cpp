class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();

        vector<long long>arr(n,0);

        unordered_map<int,vector<int>>mpp;

        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }

        for(auto &it: mpp){
            vector<int>&idx = it.second;
            int k = idx.size();

            if(k==1) continue;

            vector<long long>pre(k);
            pre[0] = idx[0];

            for(int i=1;i<k;i++){
                pre[i] = pre[i-1]+idx[i];
            } 
            long long total = pre[k-1];

            for(int t=0;t<k;t++){
                long long pos = idx[t];

                long long left = 0;
                if(t>0){
                    left = (pos*t)-(pre[t-1]);
                }
                long long right = 0;
                if(t<k-1){
                    right = (total-pre[t])-(pos*(k-1-t));
                }
                arr[idx[t]] = left+right;
            }
        }
        return arr;
    }
};