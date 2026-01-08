class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        int mask = 0;
        unordered_map<int,int>mpp;
        mpp[0] = -1;
        int ans = 0;

        for(int i=0;i<n;i++){
            char c = s[i];

            if(c=='a') mask^=(1<<0);
            if(c=='e') mask^=(1<<1);
            if(c=='i') mask^=(1<<2);
            if(c=='o') mask^=(1<<3);
            if(c=='u') mask^=(1<<4);

            if(mpp.count(mask)){
                ans = max(ans,i-mpp[mask]);
            }else{
                mpp[mask] = i;
            }
        }
        return ans;
    }
};