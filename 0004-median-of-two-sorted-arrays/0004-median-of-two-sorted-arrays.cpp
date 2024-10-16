class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int>merge(n1+n2);
        int i = 0,j=0,k=0;
        while(i<n1&&j<n2){
            if(nums1[i]>nums2[j]){
                merge[k] = nums2[j];
                j++;
            }else{
                merge[k] = nums1[i];
                i++;
            }
            k++;
        }
        while(i<n1){
            merge[k]=nums1[i];
            i++;
            k++;
        }
        while(j<n2){
            merge[k]=nums2[j];
            j++;
            k++;
        }
        int s = (n1+n2);
        int a = (s-1)/2;
        double medium;
        if((n1+n2)%2==0){
            medium = (double)(merge[a]+merge[a+1])/2;
        }else {
            medium = merge[a];
        }
        return medium;
    }
};