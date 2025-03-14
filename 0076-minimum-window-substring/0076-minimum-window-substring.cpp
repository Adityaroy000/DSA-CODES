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
        
        while(r<m){
            if(mpp[s[r]]>0) cnt++;
            mpp[s[r]]--;
            while(cnt == n){
                if(r-l+1 < mini){
                    mini = r-l+1;
                    sidx = l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }
        return (sidx == -1)? "":s.substr(sidx,mini);
    }
};