class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mpp;
        for(int i =0; i<tasks.size(); i++){
            if(mpp.find(tasks[i])!= mpp.end()){
                mpp[tasks[i]]++;
            }else{
                mpp[tasks[i]] = 1;
            }
        }
        priority_queue<int>pq;
        for(auto it: mpp){
            pq.push(it.second);
        }
        queue<pair<int,int>>p;
        int time = 0;
        while(!pq.empty() || !p.empty()){
            time++;
            if(!pq.empty()){
                int temp = pq.top();
                pq.pop();
                if((temp-1)!=0){
                    p.push({temp-1,time+n});
                }
            }
            if(!p.empty() && time == p.front().second){
                pq.push(p.front().first);
                p.pop();
            }
            
        }
        return time;
    }
};