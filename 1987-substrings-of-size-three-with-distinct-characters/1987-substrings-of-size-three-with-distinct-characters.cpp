class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map<char,int>mpp;
        int n = s.size();

        if(n<3) return 0;
        int cnt = 0;
        int start = 0,end = 0;
        while(end<n){
            mpp[s[end]]++;
            if(end-start+1 >= 3){
                if(mpp.size()==3) cnt++; 
                mpp[s[start]]==1?mpp.erase(s[start]):mpp[s[start]]--;
                start++;
            }
            end++;
        }
        return cnt;
    }
};