class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>mpp;
        for(auto it: s){
            mpp[it]++;
        }
        int even= INT_MAX,odd= INT_MIN;
        for(auto it : mpp){
            if(it.second %2 == 0){
                even = min(even ,it.second);
            }else {
                odd = max(odd,it.second);
            }
        }
        return (odd-even);
    }
};