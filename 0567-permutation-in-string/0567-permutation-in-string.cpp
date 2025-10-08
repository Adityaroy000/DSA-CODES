class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        unordered_map<char,int>mpp1;
        unordered_map<char,int>mpp2;

        for(char ch: s1){
            mpp1[ch]++;
        }

        int l=0,r=0;
        while(r<n2){
            mpp2[s2[r]]++;
            if(r-l+1 == s1.size()){
                if(mpp1 == mpp2) return true;
                mpp2[s2[l]]==1?mpp2.erase(s2[l]):mpp2[s2[l]]--;
                l++;
            }
            r++;
        }
        return false;

    }
};