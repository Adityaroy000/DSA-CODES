class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }

        char ans;
        for(int i=0;i<t.size();i++){
            if(mpp.find(t[i])!=mpp.end()){
                mpp[t[i]]==1?mpp.erase(t[i]):mpp[t[i]]--;
            }else{
                ans = t[i];
                break;
            }
        }
        return ans;
    }
};