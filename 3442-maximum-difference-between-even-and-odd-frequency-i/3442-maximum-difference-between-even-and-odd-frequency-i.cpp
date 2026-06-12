class Solution {
public:
    int maxDifference(string s) {
        int n = s.size();

        unordered_map<char,int>mpp;

        for(int x:s){
            mpp[x]++;
        }

        vector<int>even,odd;
        for(auto it : mpp){
            if(it.second % 2 == 0) even.push_back(it.second);
            else odd.push_back(it.second);
        }

        int maxi = INT_MIN;
        int e = even.size(),o = odd.size();

        for(int i=0;i<o;i++){
            for(int j=0;j<e;j++){
                maxi = max(maxi,(odd[i]-even[j]));
            }
        }
        return maxi;
    }
};