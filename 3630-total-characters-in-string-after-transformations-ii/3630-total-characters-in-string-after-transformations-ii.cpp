class Solution {
public:
    int mod = 1e9+7;
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        int n = s.length();
        vector<int>mpp(26,0);
        for(int i = 0;i<n;i++){
            mpp[s[i]-'a']++;
        }

        for(int j = 1;j<=t;j++){
            vector<int>temp(26,0);
            for(int i = 0;i<26;i++){
                char ch = i+'a';
                int freq = mpp[i];
                int size = nums[ch-'a'];
                for(int k = 1;k<=size;k++){
                    temp[(i+k)%26] = (temp[(i+k)%26]+freq)%mod;
                }
            }
            mpp = move(temp);
        }
        int res = 0;
        for(int i=0;i<26;i++ ){
            res = (res + mpp[i])%mod;
        }
        return res;
    }
};