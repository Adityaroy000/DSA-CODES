class Solution {
public:
    typedef pair<int,int>p;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();

        vector<int>ans;

        priority_queue<p,vector<p>,greater<p>>pq;
        for(int i=0;i<n;i++){
            int dist = abs(arr[i]-x);
            pq.push({dist,i});
        }

        int cnt = 0;
        while(cnt < k && !pq.empty()){
            auto it = pq.top();
            ans.push_back(arr[it.second]);
            pq.pop();
            cnt++;
        }

        sort(ans.begin(),ans.end());

        return ans;
    }
};