class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(int i=0; i<gifts.size(); i++){
            pq.push(gifts[i]);
        }
        long long sum = 0;
        while(k&&!pq.empty()){
            long long pile = pq.top();
            long long left = sqrt(pile);
            pq.pop();
            pq.push(left);
            k--;
        }
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};