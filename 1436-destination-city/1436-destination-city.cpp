class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int>mpp;
        int n = paths.size();

        for(int i=0;i<n;i++){
            string s = paths[i][0];
            string d = paths[i][1];

            mpp[s]++;
        }

        for(int i=0;i<n;i++){
            if(!mpp.count(paths[i][0])) return paths[i][0];
            if(!mpp.count(paths[i][1])) return paths[i][1];
        }

        return "";
    }
};