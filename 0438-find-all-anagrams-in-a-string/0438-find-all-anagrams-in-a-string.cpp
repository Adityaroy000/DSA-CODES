class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        unordered_map<char,int>mpps;
        unordered_map<char,int>mppp;
        for(int i=0;i<p.size();i++){
            mppp[p[i]]++;
        }

        int l=0,r=0;
        vector<int>ans;
        while(r<n){
            mpps[s[r]]++;
            if(r-l+1 == p.size()){
                if(mppp == mpps) ans.push_back(l);
                mpps[s[l]]==1?mpps.erase(s[l]):mpps[s[l]]--;
                l++;
            }
            r++;
        }
        
        return ans;
    }
};