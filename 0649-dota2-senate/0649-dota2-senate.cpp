class Solution {
public:
    string predictPartyVictory(string s) {
        int n = s.size();
        queue<int>r,d;
        for(int i=0;i<n;i++){
            if(s[i]=='R') r.push(i);
            else d.push(i);
        }

        while(!r.empty() && !d.empty()){
            int q1 = r.front(); r.pop();
            int q2 = d.front(); d.pop();

            if(q1<q2){
            r.push(q1+n);
            }else{
            d.push(q2+n);
            }
        }
        return r.empty()?"Dire":"Radiant";
    }
};