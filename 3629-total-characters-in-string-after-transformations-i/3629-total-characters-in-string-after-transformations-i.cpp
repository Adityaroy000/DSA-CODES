class Solution {
public:
    int mod = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        int n = s.length();
        vector<int>mpp(26,0);
        for(int i= 0;i<n;i++){
            mpp[s[i]-'a']++;
        }

        for(int count = 1;count<=t;count++){
            vector<int>temp(26,0);
            for(int i= 0;i<26;i++){
                char ch = i+'a';
                int freq = mpp[i];
                if(ch !='z'){
                    temp[(ch+1)-'a'] = (temp[(ch+1)-'a']+freq)%mod;
                }else{
                    temp['a'-'a'] = (temp['a'-'a']+freq)%mod;
                    temp['b'-'a'] = (temp['b'-'a']+freq)%mod;
                }
            }
            mpp = move(temp);
        }
        int ans = 0;
        for(int i= 0;i<26;i++){
            ans = (ans+mpp[i])%mod;
        }
        return ans;
    }
};