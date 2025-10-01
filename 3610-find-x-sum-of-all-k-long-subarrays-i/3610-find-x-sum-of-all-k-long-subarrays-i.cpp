class Solution {
public:
    typedef pair<int,int> p;
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int>ans;
        unordered_map<int,int>mpp;
        
        set<p>st;
        for(int i=0;i<k;i++){
            mpp[nums[i]]++;
        }
        for(auto &it:mpp){
            st.insert({it.second,it.first});
        }

        auto calcSum = [&]() {
            int sum = 0;
            auto it = st.rbegin();
            int cnt = 0;
            while(it != st.rend() && cnt < x){
                sum += (it->first * it->second);
                it++;
                cnt++;
            }
            return sum;
        };

        ans.push_back(calcSum());

        for(int i=1;i<=n-k;i++){
            int oldVal = nums[i-1];
            st.erase({mpp[oldVal],oldVal});
            mpp[oldVal]--;
            if(mpp[oldVal]>0){
                st.insert({mpp[oldVal],oldVal});
            }else{
                mpp.erase(oldVal);
            }

            int newVal = nums[i+k-1];
            if(mpp.count(newVal)){
                st.erase({mpp[newVal],newVal});
            }
            mpp[newVal]++;
            st.insert({mpp[newVal],newVal});
            ans.push_back(calcSum());
        }
        
        return ans;
    }
};