class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int n = arrivals.size();
        unordered_map<int,int>mpp;
        unordered_set<int>st;

        int l=0,r=0,cnt=0;
        while(r<n){
            mpp[arrivals[r]]++;
            if(mpp[arrivals[r]]>m){
                st.insert(r);
                mpp[arrivals[r]] == 1? mpp.erase(arrivals[r]): mpp[arrivals[r]]--;
                cnt++;
            }
            if(r-l+1 == w){
                if(st.find(l)==st.end())
                    mpp[arrivals[l]] == 1? mpp.erase(arrivals[l]): mpp[arrivals[l]]--;
                l++;
            }

            r++;
        }
        return st.size()==0?0:cnt;
    }
};