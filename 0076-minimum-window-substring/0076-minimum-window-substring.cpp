class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        int mini = INT_MAX;
        unordered_map<char,int>mpp;
        for(auto it:t){
            mpp[it]++;
        }
        int sidx = -1;
        int l=0,r=0;
        int cnt  = 0;
        unordered_map<char,int>mp;
        while(r<m){
            
            if(mpp.find(s[r])!=mpp.end()){
                mp[s[r]]++;
                if(mp[s[r]]==mpp[s[r]]){
                    cnt++;
                }
            }
        
            while(cnt == mpp.size()){
                if(r-l+1 < mini){
                    mini = r-l+1;
                    sidx = l;
                }
                if(mpp.find(s[l])!=mpp.end()){
                    if(mp[s[l]]==mpp[s[l]]) cnt--;
                    mp[s[l]]--;
                    if(mp[s[l]]==0) mp.erase(s[l]);
                }
                
                l++;
            }
            r++;
        }
        return (sidx == -1)? "":s.substr(sidx,mini);
    }
};