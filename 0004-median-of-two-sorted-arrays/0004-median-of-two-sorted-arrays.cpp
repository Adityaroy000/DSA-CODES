class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(int i = 0; i<n2; i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
        int s = nums1.size();
        int a1=s/2,a2;
        for(int i = 0; i<s; i++){
            if(s%2==0&&i==a1){
                a2 = i-1;
                break;
            }
        }
        double medi;
        if(s%2==0){
            medi = (double)(nums1[a1]+nums1[a2])/2;
        }else medi = nums1[a1];
        return medi;
    }
};