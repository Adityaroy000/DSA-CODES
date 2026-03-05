class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int r = mat.size();
        int c = mat[0].size();

        vector<pair<int,int>>ones;
        for(int i= 0;i<r;i++){
            int low = 0, high = c-1;
            int lidx = -1;
            while(low<=high){
                int mid = (high+low)/2;

                if(mat[i][mid]==0){
                    lidx = mid;
                    high = mid-1;
                }else low = mid+1;
            }
            if(lidx == -1) ones.push_back({c, i});
            else ones.push_back({lidx, i});
        }

        sort(ones.begin(),ones.end());

        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(ones[i].second);
        }
        return ans;
    }
};