class Solution {
public:
    /*
    for going in room j from i 
    hp-(damage[i]+damage[i+1]+...+damage[j]) >= req[j]
    hp-(pre[j]-pre[i-1])>=req[j]
    cant apply binary search here in this equality So
    pre[i-1] >= req[j]+pre[j]-hp;
    */
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        int n = damage.size();
        vector<long long>pre(n+1);

        for(int i=0;i<n;i++){
            pre[i+1] = pre[i]+damage[i];
        }

        long long tsum = 0;

        for(int i=1;i<=n;i++){
            int idx;
            long long td = requirement[i-1]+pre[i]-hp;
            auto it = lower_bound(pre.begin(),pre.end(),td);
            idx = it-pre.begin();
            if(idx+1>i){
                continue;
            }
            idx++;
            tsum += (i-idx+1);
        }
        return tsum;
    }
};