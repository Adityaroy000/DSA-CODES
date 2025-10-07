class Solution {
public:
    int distinctPoints(string s, int k) {
        int n = s.size();
        int x=0,y=0;
        for(int i=0;i<n;i++){
            if(s[i]=='U'){
                y += 1;
            }else if(s[i]=='D'){
                y -= 1;
            }else if(s[i] == 'L'){
                x -= 1;
            }else{
                x += 1;
            }
        }
        int l=0,r=0;
        set<pair<int,int>>st;
        while(r<n){
            if(s[r]=='U'){
                y -= 1;
            }else if(s[r]=='D'){
                y += 1;
            }else if(s[r] == 'L'){
                x += 1;
            }else if(s[r] == 'R'){
                x -= 1;
            }
            if(r-l+1 == k){
                st.insert({x,y});
                if(s[l]=='U'){
                    y += 1;
                }else if(s[l]=='D'){
                    y -= 1;
                }else if(s[l] == 'L'){
                    x -= 1;
                }else if(s[l] == 'R'){
                    x += 1;
                }
                l++;
            }
            r++;
        }
        return st.size()==0?1:st.size();
    }
};