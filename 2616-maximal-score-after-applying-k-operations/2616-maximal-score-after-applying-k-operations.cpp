class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> maxHeap(nums.begin(), nums.end());
        
        long long score = 0;
        
        for (int i = 0; i < k; i++) {
            int maxValue = maxHeap.top();
            maxHeap.pop();
            
            score += maxValue;
            
            int newValue = (maxValue + 2) / 3; 
            maxHeap.push(newValue);
        }
        
        return score;
    }
};