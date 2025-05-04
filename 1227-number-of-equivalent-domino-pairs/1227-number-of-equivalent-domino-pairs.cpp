class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        for(int i = 0;i<n;i++){
            if(dominoes[i][0]>dominoes[i][1]) swap(dominoes[i][0],dominoes[i][1]);
        }
        map<pair<int,int>,int>mpp;
        
        for(int i =0;i<n;i++){
            mpp[{dominoes[i][0],dominoes[i][1]}]++;
        }
        int ans = 0;
        for(auto &it : mpp){
            ans += (it.second * (it.second-1))/2;
        }
        return ans;                        
    }
};