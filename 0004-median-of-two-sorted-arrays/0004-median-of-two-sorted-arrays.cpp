class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int>merge;
        int left =0,right=0;
        while(left<m&&right<n){
            if(nums1[left]<nums2[right]){
                merge.push_back(nums1[left]);
                left++;
            }else{
                merge.push_back(nums2[right]);
                right++;
            }
        }
        while(left < m){
            merge.push_back(nums1[left]);
            left++;
        }
        while(right < n){
            merge.push_back(nums2[right]);
            right++;
        }
        double ans;
        int s = merge.size();
        int low = 0,high = s-1;
        int mid = (high+low)/2;
        if(s%2==0){
            ans =(double) (merge[mid]+merge[mid+1])/ 2;
        }else{
            ans =(double) merge[mid];
        }
        return ans;
    }
};