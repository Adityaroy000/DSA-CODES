class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if(n==1) return 0;

        int cnt = 0, ans = INT_MAX;
        string t = s;
        bool flag = true;
        for(int i=0;i<n;i++){
            if(flag) {
                t[i] = '1';
                flag = false;
            }else{
                t[i] = '0';
                flag = true;
            }
        }

        for(int i=0;i<n;i++){
            if(s[i] != t[i]) cnt++;
        }

        ans = min(ans,cnt);
        flag = true;
        string p = s;
        cnt=0;
        for(int i=0;i<n;i++){
            if(flag) {
                p[i] = '0';
                flag = false;
            }else{
                p[i] = '1';
                flag = true;
            }
        }
        for(int i=0;i<n;i++){
            if(s[i] != p[i]) cnt++;
        }

        ans = min(ans,cnt);
        return ans;
    }
};