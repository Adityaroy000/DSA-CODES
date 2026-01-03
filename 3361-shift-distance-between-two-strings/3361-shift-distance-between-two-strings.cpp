class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        int n = s.size();
        vector<long long>pn(27),pp(27);
        for(int i=0;i<26;i++){
            pn[i+1] = pn[i] + nextCost[i];
            pp[i+1] = pp[i] + previousCost[i];
        }

        vector<int>sidx(n),tidx(n);
        for(int i=0;i<n;i++){
            int indexS = s[i]-'a';
            sidx[i] = indexS;
            int indexT = t[i]-'a';
            tidx[i] = indexT;
        }
        long long ans = 0;
        for(int k=0;k<n;k++){
            int i = sidx[k];
            int j = tidx[k];

            long long mincost = 0;
            if(i!=j){
                if(i<j){
                    long long costone = pn[j]-pn[i];
                    long long pcostOne = (pp[i+1]-pp[0]) + (pp[26]-pp[j+1]);
                    mincost = min(costone,pcostOne);
                }else{
                    long long costtwo = (pn[26]-pn[i]) + pn[j];
                    long long pcostTwo = pp[i+1]-pp[j+1];
                    mincost = min(costtwo,pcostTwo);
                }
            }
            ans += mincost;
        }
        return ans;
    }
};