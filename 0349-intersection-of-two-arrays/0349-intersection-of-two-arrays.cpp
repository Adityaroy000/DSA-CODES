class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int>ans;

        unordered_set<int>st1(nums1.begin(),nums1.end()),st2;

        for(int x : nums2){
            if(st1.count(x) && st2.count(x)==0) {
                ans.push_back(x);
                st2.insert(x);
            }
        }

        return ans;
    }
};