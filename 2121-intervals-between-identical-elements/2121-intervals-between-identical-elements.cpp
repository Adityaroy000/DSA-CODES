class Solution {
public:
    /*
    for given index vector : [p0,p1,p2,........,pk]
    let say we want find distance of pj from each ele
    So, left sum = (pj-p0)+(pj-p1)+(pj-p2)+ ..... +(pj-pj-1)
                 = (pj*j) - (p0+p1+p2+...+pj-1) can be done with prefix sum
        right sum = (pj+1 -pj)+(pj+2 - pj)+....+(pk-pj)
                  = (pj+1 + pj+2 + .... + pk)-((k-j)*pj) can also be done with prefix sum
        answer will be just left sum + right sum.
    */
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>>mpp;
        vector<long long>ans(n);

        for(int i=0;i<n;i++){
            mpp[arr[i]].push_back(i);
        }

        for(auto it:mpp){
            const vector<int>temp = it.second;
            vector<long long>pre(temp.size()+1);
            long long tsum = 0;
            for(int i=0;i<temp.size();i++){
                tsum += temp[i];
                pre[i+1] = pre[i]+temp[i];
            }
            for(int i=0;i<temp.size();i++){
                int leftsize = i;
                int rightsize = temp.size()-1-i;
                int curr = temp[i];
                long long sufsum = tsum - pre[i] - temp[i];

                long long lsum = (1LL*curr*leftsize) - pre[i];
                long long rsum = sufsum - (1LL*rightsize*curr);
                ans[temp[i]] = lsum+rsum;
            }
        }
        return ans;
    }
};