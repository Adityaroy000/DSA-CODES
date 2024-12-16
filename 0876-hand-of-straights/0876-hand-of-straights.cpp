class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        unordered_map<int,int>mpp;
        if(n%groupSize != 0) return false;
        for(int card : hand){
            mpp[card]++;
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it : mpp){
            pq.push(it.first);
        }
        while(!pq.empty()){
            int card = pq.top();
            for(int i = 0; i<groupSize;i++){
                int currcard = card+i;
                if(mpp[currcard]==0) return false;
                mpp[currcard]--;
                if(mpp[currcard]==0){
                    if(currcard==pq.top()) pq.pop();
                }
            }
        }            
        return true;
    }
};