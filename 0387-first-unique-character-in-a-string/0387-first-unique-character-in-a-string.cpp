class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();

        unordered_map<char,pair<int,int>>mpp;

        for(int i=0;i<n;i++){
            mpp[s[i]].first++;
            mpp[s[i]].second = i;
        }

        int ans = INT_MAX;

        for(auto &[ch, p] : mpp){
            if(p.first == 1) ans = min(ans,p.second);
        }
       

        return ans==INT_MAX?-1:ans;
    }
};