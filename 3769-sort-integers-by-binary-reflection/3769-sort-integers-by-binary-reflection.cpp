class Solution {
public:
    vector<string>convertToBin(vector<int>& nums){
        vector<string>bin;
        int n = nums.size();
        for(int i=0;i<n;i++){
            string s;
            int num = nums[i];
            while(num>0){
                int rem = num%2;
                s.push_back('0'+rem);
                num /= 2;
            }
            bin.push_back(s);
        }
        return bin;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        int n = nums.size();
        vector<string>bin = convertToBin(nums);

        vector<pair<int,int>>temp;
        for(int i=0;i<n;i++){
            int x = stoi(bin[i],nullptr,2);
            temp.push_back({x,nums[i]});
        }

        sort(temp.begin(),temp.end(),[](const pair<int,int>&a, const pair<int,int>& b){
            if(a.first == b.first) return a.second<b.second;
            else return a.first<b.first;
        });
        vector<int>ans;
        for(auto &it: temp){
            ans.push_back(it.second);
        }
        return ans;
    }
};