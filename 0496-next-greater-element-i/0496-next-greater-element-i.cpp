class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int>mpp;
        for(int i = 0; i<nums2.size();i++){
            mpp[nums2[i]] = i;
        }
        for(int i = 0 ;i<nums1.size();i++){
            if(mpp.find(nums1[i])!=mpp.end()){
                int idx = mpp[nums1[i]];
                int j;
                if((idx+1)<nums2.size()){
                    j = idx+1;
                    int cnt = 0;
                    for(int k = j;k<nums2.size();k++){
                        if(nums2[k]>nums2[idx]){
                            ans.push_back(nums2[k]);
                            cnt=1;
                            break;
                        }
                    }
                    if(cnt ==0){
                        ans.push_back(-1);
                    }
                }else{
                    ans.push_back(-1);    
                }  
            }
        }
        return ans;
    }
};