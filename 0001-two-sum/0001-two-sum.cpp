class Solution {
private:
    void merge(vector<pair<int,int>>& nums, int left,int mid, int right){
        int l = left;
        int r = mid+1;
        vector<pair<int,int>>temp;
        while(l<=mid && r<=right){
            if(nums[l].first<nums[r].first){
                temp.push_back(nums[l]);
                l++;
            }else{
                temp.push_back(nums[r]);
                r++;
            }
        }
        while(l<=mid){
            temp.push_back(nums[l]);
            l++;
        }
        while(r<=right){
            temp.push_back(nums[r]);
            r++;
        }
        for(int i=left;i<=right;i++){
            nums[i] = temp[i-left];
        }
    }
    void mergeSort(vector<pair<int,int>>& nums,int left,int right){
        if(left>=right) return;
        int mid = left+(right-left)/2;

        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);

        merge(nums,left,mid,right);
    }
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        mergeSort(arr,0,n-1);

        int left= 0,right = n-1;
        int sum = 0;
        while(left<right){
            sum = arr[left].first + arr[right].first;
            if(sum > target){
                right--;
            }else if(sum < target){
                left++;
            }else{
                return {arr[left].second,arr[right].second};
            }
        }
        return {};
    }
};