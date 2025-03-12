class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int cnt  = 0,ans = 0;
        int l = 0,r = 0;
        unordered_map<char,int>mpp;
        while(r<n){
            mpp[s[r]]++;
            
            while(mpp.size()==3){
                ans++;
                ans += n-r-1;
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;
            }
            r++;
        }
            
        return ans;
    }
};