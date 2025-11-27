class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        int cnt = 0;

        for(int i=0;i<n;i++){
            if(cnt > 0){
                if(s[i]=='a') return false;
            }
            else {
                if(s[i]!='a') cnt++;
            }
        }
        return true;
    }
};