class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        priority_queue<int>maxHeap;
        priority_queue<int,vector<int>,greater<int>>past;

        sort(queries.begin(),queries.end());
        
        int j= 0;
        int usedQuery = 0;
        for(int i=0;i<n;i++){
            while(j<q && queries[j][0]==i){
                maxHeap.push(queries[j][1]);
                j++;
            }

            nums[i] -= past.size();

            while(nums[i]>0 && !maxHeap.empty() && maxHeap.top()>=i){
                int ending = maxHeap.top();
                maxHeap.pop();

                usedQuery++;
                past.push(ending);
                nums[i]--;
            }

            if(nums[i]>0) return -1;

            while(!past.empty() && past.top()<=i){
                past.pop();
            }
        }
        return q-usedQuery;
    }
};