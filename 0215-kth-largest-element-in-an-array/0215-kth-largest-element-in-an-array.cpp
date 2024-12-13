class Solution {
public:
    void heapify(vector<int>& nums,int i){
        int n = nums.size();
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        if(left<n && nums[left]>nums[largest]){
            largest = left;
        }
        if(right<n && nums[right]>nums[largest]){
            largest = right;
        }
        if(largest != i){
            swap(nums[largest],nums[i]);
            heapify(nums,largest);
        }
    }
    void deletion(vector<int>& nums,int &n){
        nums[0] = nums[n-1];
        n--;
        int i = 0;
        while(i<n){
            int largest = i;
            int left = 2*i + 1;
            int right = 2*i + 2;
            if(left<n && nums[left]>nums[largest]){
                largest = left;
            }
            if(right<n && nums[right]>nums[largest]){
                largest = right;
            }
            if(largest == i) break;
            swap(nums[i],nums[largest]);
            i = largest;
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = (n/2)-1; i>=0; i--){
            heapify(nums,i);
        }
        for(int i = 1; i<=k-1; i++){
            deletion(nums,n);
        }
        return nums[0];
    }
};