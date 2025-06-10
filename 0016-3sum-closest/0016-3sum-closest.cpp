class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
         int n = arr.size();
        sort(arr.begin(),arr.end());
        
        int closestSum = arr[0]+arr[1]+arr[2];
        int mingap = abs(closestSum-target);

        for(int i=0;i<n;i++){
            int left = i+1;
            int right = n-1;
            while(left<right){
                int sum = arr[i]+arr[left]+arr[right];
                int gap = abs(sum-target);
                if(gap<mingap || (gap==mingap && closestSum<sum)){
                    closestSum = sum;
                    mingap = gap;
                }
                if(sum>target){
                    right--;
                }else if(sum<target){
                    left++;
                }else return target;
            }
        }
        
        return closestSum;
    }
};