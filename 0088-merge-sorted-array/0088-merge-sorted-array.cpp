class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = 0;
        int right = 0;
        int idx = 0;
        vector<int>n3;
        while(left < m && right < n){
            if(nums1[left] <= nums2[right]){
                n3.push_back(nums1[left]);;
                left++;
            }
            else{
                n3.push_back(nums2[right]);;
                right++;
            }
        }
        while(left < m){
            n3.push_back(nums1[left]);
            left++;
        }
        while(right < n){
            n3.push_back(nums2[right]);
            right++;
        }
        nums1 = n3;
    }
};