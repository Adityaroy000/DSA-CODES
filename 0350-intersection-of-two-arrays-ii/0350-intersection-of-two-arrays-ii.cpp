class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int>ans;
        unordered_map<int,int>mpp1;

        for(int i=0;i<n1;i++) mpp1[nums1[i]]++;

        for(int i=0;i<n2;i++){
            int el = nums2[i];
            if(mpp1.count(el)) {
                ans.push_back(el);
                if(mpp1[el]==1) mpp1.erase(el);
                else mpp1[el]--;
            }
        }
        return ans;
    }
};